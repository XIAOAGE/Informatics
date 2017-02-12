struct node
{
int x, y, val;
bool operator<(const node& b) const
{
return val > b.val;
}
};
