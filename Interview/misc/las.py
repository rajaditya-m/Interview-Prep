def look_and_say(sequence_number):
    if sequence_number==1:
        return 1
    else:
        prev = look_and_say(sequence_number-1)
        str_prev = str(prev)
        ctr = 0
        prev_ch = None
        new_num = ''
        for ch in str_prev:
            if ch==prev_ch:
                ctr += 1 
            else:
                if prev_ch:
                    new_num += (str(ctr)+prev_ch)
                ctr = 1
                prev_ch = ch
        if prev_ch:
            new_num += (str(ctr)+prev_ch)
        return int(new_num)

print(look_and_say(4))