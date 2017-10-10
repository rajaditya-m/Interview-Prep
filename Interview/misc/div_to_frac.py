def divide(numerator,denominator):
    has_neg = False
    if numerator<0:
        numerator *= -1
        has_neg = not has_neg
    if denominator<0:
        denominator *= -1
        has_neg = not has_neg
    dec_part = numerator // denominator
    num = numerator % denominator
    hashtable = set()
    recurring = False
    frac_part = ''
    while num:
        hashtable.add(num)
        num = num*10
        frac_digit = num // denominator
        frac_part += str(frac_digit)
        num = num % denominator
        if num in hashtable:
            recurring = True
            break
    if has_neg:
        if recurring:
            return '-{}.[{}]'.format(dec_part,frac_part)
        else:
            return '-{}.{}'.format(dec_part,frac_part)
    else:
        if recurring:
            return '{}.[{}]'.format(dec_part,frac_part)
        else:
            return '{}.{}'.format(dec_part,frac_part)

print(divide(-8,7))