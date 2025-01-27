#include "Sort_list.h"

int main()
{

  SortList<int> my_list;
  my_list.add_item(4);
  my_list.add_item(7);
  my_list.add_item(2);
  my_list.add_item(9);
  my_list.add_item(2);

  my_list.print_items();
  my_list.sort();
  my_list.print_items();





  return 0;
}