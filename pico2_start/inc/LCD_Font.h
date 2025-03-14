#ifndef LCD_FONT_H_INCLUDED
#define LCD_FONT_H_INCLUDED

#include "custom_types.h"


typedef enum selection {
    space, 
    expt, 
    quote, 
    hash,
    dollar,
    percent,
    ampersand,
    apostrophe,
    lparenth,
    rparenth,
    asterisk,
    plus,
    comma,
    minus,
    period,
    backslash,

    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    colon,
    semicolon,
    larrow,
    equal,
    rarrow,
    question,

    at,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    lbracket,
    yen,
    rbracket,
    carrot,
    underscore,

    mark,
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,

    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z,
    lcurly,
    vertline,
    rcurly,
    larrow_full,
    rarrow_full
}fsel;

extern const u8 LCD_font[];

/**
 * Setting pos equal to the value in enum fsel at that position
 * Example: value = '!' this correlates with expt in fsel, thus pos will equal the value of expt casted to u32
 * Pos will be used later as a way to pull a value from the font array
 */
void LCD_decode(i8 value, u32* pos);

void LCD_char_send(i8* val, u32 size, u32* pos);

void nibble_split(u8* upper, u8* lower, u8 byte);
#endif