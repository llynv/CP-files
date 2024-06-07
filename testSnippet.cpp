while (l < r)
{
    ll mid = (l + r) / 2;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll left, right, pos;
    cin >> pos;
    if (l == r - 1)
    {
        cout << "! " << (l ^ r ^ pos) << "\n";
        cout.flush();
        return;
    }
    if (pos <= mid)
    {
        cout << "? " << l << " " << mid << "\n";
        cout.flush();
        cin >> left;
        if (left == pos)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    else
    {
        cout << "? " << mid << " " << r << "\n";
        cout.flush();
        cin >> right;
        if (right != pos)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    if (l == r - 1)
    {
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        cin >> pos;
        cout << "! " << (l ^ r ^ pos) << "\n";
        cout.flush();
        return;
    }
    if (l == r)
    {
        cout << "! " << l << "\n";
        cout.flush();
        return;
    }
}