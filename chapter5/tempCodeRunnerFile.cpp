st(&pdata))
    {
        if(pdata%2 == 0)
        {
            list.LRemove();
        }

        while(list.LNext(&pdata))
        {
            if(pdata%2 == 0)
            {
                list.LRemove();
            }
        }
    }