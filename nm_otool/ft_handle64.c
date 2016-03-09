//ne pas oublier de mettre le header

#include "nm_otool.h"

void print_symb(int nsyms, int symoff, int stroff, char *map_ptr)
{
        int                     i;
        char                    *strtable;
        struct  nlist_64        *array;

        array = (void *)map_ptr + symoff;
        strtable = (void *)map_ptr + stroff;
        i = 0;
        while (i < nsyms)
        {
                ft_putstr(strtable + array[i].n_un.n_strx); //nom du flag en 3e
		//a tester
		ft_putstr(strtable + array[i].n_type); //type de flag (T,U etc) en 2e
		ft_putstr(strtable + array[i].n_sect); //numero de section en 1er
		ft_putstr(strtable + array[i].n_desc); //a voir pas sur
		ft_putstr(strtable + array[i].n_value); //a voir pas sur
                i++;
        }
}

void ft_nm_handle64(char *map_ptr)
{
        int                     nbcmds;
        int                     i;
        struct mach_header_64   *header;
        struct load_command     *lc;
        struct symtab_command   *sym;

        i = 0;
        header = (struct mach_header_64 *) map_ptr;
        nbcmds = header->ncmds;
        lc = (void *)map_ptr + sizeof(*header);
        while (i < nbcmds)
        {
                if (lc->cmd = LC_SYMTAB)
                {
                        sym = (struct symtab_command *) lc;
                        print_symb(sym->nsyms, sym->symoff, \
                                sym->stroff, map_ptr);
                        break; //a virer
                }
                lc = (void *)lc + lc->cmdsize;
                i++;
        }
}
