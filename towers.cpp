#include <iostream>
#include <getopt.h>

void TowersOfHanoi(int n, int start, int end, int middle)
{
    if (n == 1)
    {
        std::cout << start << "\t" << end << std::endl;
        return;
    }

    TowersOfHanoi(n - 1, start, middle, end);
    std::cout << start << "\t" << end << std::endl;
    TowersOfHanoi(n - 1, middle, end, start);
}

int main(int argc, char *argv[])
{
    // define long options
    static struct option long_opts[] = {
        {"start", required_argument, 0, 's'},
        {"end", required_argument, 0, 'e'},
        {"num-disks", required_argument, 0, 'n'},
        {0, 0, 0, 0} // this denotes the end of our options.
    };

    // now process the options:
    char c; // to hold the option
    int opt_index = 0;
    int n = 0, start = 1, end = 2; /* to store inputs to the towers function. */
    while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1)
    {
        switch (c)
        {
            case 's': // process option s
                start = atoi(optarg);
                break;
            case 'e': // process option e
                end = atoi(optarg);
                break;
            case 'n': // process option n
                n = atoi(optarg);
                break;
            case '?': // this will catch unknown options.
                // here is where you would yell at the user.
                // although, getopt will already print an error message.
                return 1;
        }
    }

    TowersOfHanoi(n, start, end, 6 - start - end);

    return 0;
}
