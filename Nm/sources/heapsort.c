/*
** heapsort.c for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar 12 21:32:59 2014 Barthelemy Delemotte
** Last update Wed Mar 12 21:44:41 2014 Barthelemy Delemotte
*/

#include		<stdbool.h>

#include		"nm.h"

static inline bool	isOrdered(void **tree,
				  const size_t child1,
				  const size_t child2,
				  const t_cmp_funct cmpFunct)
{
  if (cmpFunct(tree[child1 - 1], tree[child2 - 1]) > 0)
    return (true);
  return (false);
}

static inline void	swap(void **tree, const size_t node, const size_t child)
{
  void			*tmp;

  tmp = tree[node - 1];
  tree[node - 1] = tree[child - 1];
  tree[child - 1] = tmp;
}

static void		siftDown(void **tree,  size_t node, size_t size,
				 t_cmp_funct cmpFunct)
{
   size_t		child;

   child = 2 * node;
   while (child <= size)
     {
       if (child < size && !isOrdered(tree, child, child + 1, cmpFunct))
	 child++;
       if (!isOrdered(tree, node, child, cmpFunct))
	 swap(tree, node, child);
       node = child;
       child = 2 * node;
     }
}

static void		siftUp(void **tree,  size_t node, t_cmp_funct cmpFunct)
{
   size_t		parent;

   while (node > 1)
     {
       parent = node / 2;
       if (!isOrdered(tree, parent, node, cmpFunct))
	 swap(tree, parent, node);
       else
	 return ;
       node = parent;
     }
}

void			heapsort(void **tree, size_t size, t_cmp_funct cmpFunct)
{
  size_t		i;

  i = 2;
  while (i <= size)
    {
      siftUp(tree, i, cmpFunct);
      i++;
    }
  siftDown(tree, 1, size, cmpFunct);
  i = size;
  while (i >= 2)
    {
      swap(tree, 1, i);
      siftDown(tree, 1, i - 1, cmpFunct);
      i--;
    }
}
