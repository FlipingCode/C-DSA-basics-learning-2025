int j = 1;
    while (j < max)
    {
        if (j == 1)
        {
            print("************");
        }

        x = peep(j);

        printf("value: %d \n", x);

        if (j == max - 1)
        {
            print("************");
        }
        j = j + 1;
    }