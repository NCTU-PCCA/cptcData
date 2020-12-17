#include <bits/stdc++.h>
using namespace std;

ifstream in;
ofstream out;
void createInteractiveProblem(int argc, char **argv) {
    /* Check argument number */
    if (argc - 1 != 2) {
        cerr << "invalid number of arguments: " << argc - 1 << ", while 2 expected" << '\n';
        exit(1);
    }

	/* Make stdin/stdout unbuffered, just to be sure */
	if (setvbuf(stdin,  NULL, _IONBF, 0) != 0 ||
	    setvbuf(stdout, NULL, _IONBF, 0) != 0) {
        cerr << "cannot set unbuffered I/O" << '\n';
        exit(1);
	}

    /* Open jury input and output file */
    in.open(argv[1], std::ifstream::in);
    if (in.fail()) {
        cerr << "could not open input file" << '\n';
        exit(1);
    }
    out.open(argv[2], std::ofstream::out);
    if (out.fail()) {
        cerr << "could not open output file" << '\n';
        exit(1);
    }
}
void destroyInteractiveProblem() {
    /* Close stdout to stop the judgement */
    fclose(stdout);

    /* Read all output from user's program */
    string rest;
    while (getline(cin, rest))
        out << rest << '\n';
	cerr << "Jury program exited successfully\n";
}
void interact() {
    int safe_layer; in >> safe_layer;
    int remain_eggs = 3, remain_tries = 30;

    string op; while (cin >> op) {
        /* Check query type */
        if (op.size() != 1 || (op[0] != '!' && op[0] != '?')) {
            out << "invalid query type: " << op << "." << '\n';
            break;
        }

        if (op[0] == '?') {
            /* Check invalid query scenario */
            if (remain_eggs == 0) {
                out << "no enough egg." << '\n';
                break;
            }
            if (remain_tries == 0) {
                out << "too much queries." << '\n';
                break;
            }

            /* Check query format */
            int query_layer; cin >> query_layer;
            if (cin.fail()) {
                out << "invalid query format\n";
                break;
            }
            if (query_layer <= 0 || query_layer >= 1002) {
                out << "invalid query layer: " << query_layer << '\n';
                break;
            }

            /* Return answer */
            remain_tries--;
            if (query_layer <= safe_layer)
                cout << "SAFE" << endl;
            else {
                cout << "BROKEN" << endl;
                remain_eggs--;
            }
        } else if (op[0] == '!') {
            /* Check query format */
            int ans_layer; cin >> ans_layer;
            if (cin.fail()) {
                out << "invalid query format\n";
                break;
            }

            /* Store user's answer */
            out << ans_layer << '\n';
            break;
        }
    }
}
int main(int argc, char **argv) {
    createInteractiveProblem(argc, argv);
    interact();
    destroyInteractiveProblem();
    return 0;
}
