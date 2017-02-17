#include "lem_in.h"
void    ft_putdigit_base(unsigned long n, unsigned int base)
{
    if (n > base || base > 62 || base < 2)
        return ;
    if (n < 10)
        ft_putchar(n + '0');
    else if (n < 36)
        ft_putchar(n - 10 + 'A');
    else
        ft_putchar(n - 36 + 'a');
}
void        ft_putnbr_base(unsigned int n, unsigned int base)
{
    if (n > base - 1)
    {
        ft_putnbr_base(n / base, base);
        ft_putnbr_base(n % base, base);
    }
    else
        ft_putdigit_base(n, base);
}

static void    ft_pnbr(int n)
{
    if (n < 0x10)
        ft_putchar('0');
    ft_putnbr_base(n, 16);
}

static void    ft_pstr(unsigned char *s, size_t j)
{
    size_t    i;

    i = -1;
    ft_putchar('"');
    while (++i < j)
    {
        if (ft_isprint(s[i]))
            ft_putchar(s[i]);
        else
            ft_putchar('.');
    }
    while (i++ < 16)
        ft_putchar('.');
    ft_putchar('"');
    ft_putchar('\n');
}

void        hex_dump(void *ptr, size_t size)
{
    unsigned char    *data;
    size_t            i;
    size_t            stop_offset;

    data = (unsigned char *)ptr;
    i = -1;
    while (++i < size)
    {
        ft_pnbr((int)data[i]);
        ft_putchar(' ');
        if ((i + 1) % 8 == 0)
            ft_putchar(' ');
        if ((i + 1) % 16 == 0)
            ft_pstr(data + i - 15, 16);
    }
    stop_offset = i;
    while (i++ % 16)
    {
        if (i % 8 == 0)
            ft_putchar(' ');
        write(1, "   ", 3);
    }
    if (i - 1 > stop_offset)
        ft_pstr(data + i - 15, i - stop_offset);
}