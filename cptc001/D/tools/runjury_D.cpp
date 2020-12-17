#include <bits/stdc++.h>

using namespace std;

void interact(ifstream &in, ofstream &out) {
    int safe_layer; // Egg will be safe if x <= safe_layer
    in >> safe_layer;

    int remain_eggs = 3, remain_tries = 30;

    while (1) {
        string op; cin >> op;
        if (op.size() != 1 && op[0] != '!' && op[0] != '?') {
            out << "invalid query type: " << op << "." << '\n';
            break;
        }

        if (op[0] == '?') {
            if (remain_eggs == 0) {
                out << "no extra egg." << '\n';
                break;
            }

            if (remain_tries == 0) {
                out << "too much queries." << '\n';
                break;
            }

            remain_tries--;

            int query_layer; cin >> query_layer;
            if (query_layer <= 0 || query_layer >= 1001) {
                out << "invalid query layer: " << query_layer << '\n';
                break;
            }

            if (query_layer <= safe_layer)
                cout << "SAFE" << endl;
            else {
                cout << "BROKEN" << endl;
                remain_eggs--;
            }
        } else if (op[0] == '!') {
            int ans_layer; cin >> ans_layer;
            out << ans_layer << '\n';
            break;
        }
    }
}

int main(int argc, char **argv) {
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

    ifstream in;
    in.open(argv[1], std::ifstream::in);
    if (in.fail()) {
        cerr << "could not open input file" << '\n';
        exit(1);
    }

    ofstream out;
    out.open(argv[2], std::ofstream::out);
    if (out.fail()) {
        cerr << "could not open output file" << '\n';
        exit(1);
    }

    interact(in, out);

	/* We're done, send EOF */
	fclose(stdout);

	cerr << "jury program exited successfully\n";
	return 0;
}

