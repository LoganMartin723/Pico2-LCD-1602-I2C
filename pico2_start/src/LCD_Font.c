#include "../inc/custom_types.h"
#include "../inc/LCD_Font.h"

const u8 LCD_font[] = {
    0b00100000, // space
    0b00100001, // !
    0b00100010, // "
    0b00100011, // #
    0b00100100, // $
    0b00100101, // %
    0b00100110, // &
    0b00100111, // '
    0b00101000, // (
    0b00101001, // )
    0b00101010, // *
    0b00101011, // +
    0b00101100, // ,
    0b00101101, // -
    0b00101110, // .
    0b00101111, // /

    0b00110000, // 0
    0b00110001, // 1
    0b00110010, // 2
    0b00110011, // 3
    0b00110100, // 4
    0b00110101, // 5
    0b00110110, // 6
    0b00110111, // 7
    0b00111000, // 8
    0b00111001, // 9
    0b00111010, // :
    0b00111011, // ;
    0b00111100, // <
    0b00111101, // =
    0b00111110, // >
    0b00111111, // ?

    0b01000000, // @
    0b01000001, // A
    0b01000010, // B
    0b01000011, // C
    0b01000100, // D
    0b01000101, // E
    0b01000110, // F
    0b01000111, // G
    0b01001000, // H
    0b01001001, // I
    0b01001010, // J
    0b01001011, // K
    0b01001100, // L
    0b01001101, // M
    0b01001110, // N
    0b01001111, // O

    0b01010000, // P
    0b01010001, // Q
    0b01010010, // R
    0b01010011, // S
    0b01010100, // T
    0b01010101, // U
    0b01010110, // V
    0b01010111, // W
    0b01011000, // X
    0b01011001, // Y
    0b01011010, // Z
    0b01011011, // [
    0b01011100, // Yen
    0b01011101, // ]
    0b01011110, // ^
    0b01011111, // _

    0b01100000, // `
    0b01100001, // a
    0b01100010, // b
    0b01100011, // c
    0b01100100, // d
    0b01100101, // e
    0b01100110, // f
    0b01100111, // g
    0b01101000, // h
    0b01101001, // i
    0b01101010, // j
    0b01101011, // k
    0b01101100, // l
    0b01101101, // m
    0b01101110, // n
    0b01101111, // o

    0b01110000, // p
    0b01110001, // q
    0b01110010, // r
    0b01110011, // s
    0b01110100, // t
    0b01110101, // u
    0b01110110, // v
    0b01110111, // w
    0b01111000, // x
    0b01111001, // y
    0b01111010, // z
    0b01111011, // {
    0b01111100, // |
    0b01111101, // }
    0b01111110, // ->
    0b01111111, // <-
};

/**
 * Setting pos equal to the value in enum fsel at that position
 * Example: value = '!' this correlates with expt in fsel, thus pos will equal the value of expt casted to u32
 * Pos will be used later as a way to pull a value from the font array
 */
void LCD_decode(i8 value, u32* pos)
{
    fsel setPosition;
    switch(value)
    {
        case ' ':
            setPosition = space;
            break;

        case '!':
            setPosition = expt;
            break;

        case '"':
            setPosition = quote;
            break;

        case '#':
            setPosition = hash;
            break;

        case '$':
            setPosition = dollar;
            break;

        case '%':
            setPosition = percent;
            break; 

        case '&':
            setPosition = ampersand;
            break;

        // case "'":
        //     *pos = apostrophe;
        //     break;

        case '(':
            setPosition = lparenth;
            break;

        case ')':
            setPosition = rparenth;
            break;

        case '*':
            setPosition = asterisk;
            break;

        case '+':
            setPosition = plus;
            break;

        case ',':
            setPosition = comma;
            break;

        case '-':
            setPosition = minus;
            break;

        case '.':
            setPosition = period;
            break;

        case '/':
            setPosition = backslash;
            break;



        case '0':
            setPosition = zero;
            break;

        case '1':
            setPosition = one;
            break;

        case '2':
            setPosition = two;
            break;

        case '3':
            setPosition = three;
            break;

        case '4':
            setPosition = four;
            break;

        case '5':
            setPosition = five;
            break; 

        case '6':
            setPosition = six;
            break;

        case '7':
            setPosition = seven;
            break;

        case '8':
            setPosition = eight;
            break;

        case '9':
            setPosition = nine;
            break;

        case ':':
            setPosition = colon;
            break;

        case ';':
            setPosition = semicolon;
            break;

        case '<':
            setPosition = larrow;
            break;

        case '=':
            setPosition = equal;
            break;

        case '>':
            setPosition = rarrow;
            break;

        case '?':
            setPosition = question;
            break;


        case '@':
            setPosition = at;
            break;

        case 'A':
            setPosition = A;
            break;

        case 'B':
            setPosition = B;
            break;

        case 'C':
            setPosition = C;
            break;

        case 'D':
            setPosition = D;
            break;

        case 'E':
            setPosition = E;
            break;

        case 'F':
            setPosition = F;
            break; 

        case 'G':
            setPosition = G;
            break;

        case 'H':
            setPosition = H;
            break;

        case 'I':
            setPosition = I;
            break;

        case 'J':
            setPosition = J;
            break;

        case 'K':
            setPosition = K;
            break;

        case 'L':
            setPosition = L;
            break;

        case 'M':
            setPosition = M;
            break;

        case 'N':
            setPosition = N;
            break;

        case 'O':
            setPosition = O;
            break;



        case 'P':
            setPosition = P;
            break;

        case 'Q':
            setPosition = Q;
            break;

        case 'R':
            setPosition = R;
            break;

        case 'S':
            setPosition = S;
            break;

        case 'T':
            setPosition = T;
            break;

        case 'U':
            setPosition = U;
            break;

        case 'V':
            setPosition = V;
            break; 

        case 'W':
            setPosition = W;
            break;

        case 'X':
            setPosition = X;
            break;

        case 'Y':
            setPosition = Y;
            break;

        case 'Z':
            setPosition = Z;
            break;

        case '[':
            setPosition = lbracket;
            break;

        // case '':
        //     *pos = L;
        //     break;

        case ']':
            setPosition = rbracket;
            break;

        case '^':
            setPosition = carrot;
            break;

        case '_':
            setPosition = underscore;
            break;


        case '`':
            setPosition = mark;
            break;

        case 'a':
            setPosition = a;
            break;

        case 'b':
            setPosition = b;
            break;

        case 'c':
            setPosition = c;
            break;

        case 'd':
            setPosition = d;
            break;

        case 'e':
            setPosition = e;
            break;

        case 'f':
            setPosition = f;
            break; 

        case 'g':
            setPosition = g;
            break;

        case 'h':
            setPosition = h;
            break;

        case 'i':
            setPosition = i;
            break;

        case 'j':
            setPosition = j;
            break;

        case 'k':
            setPosition = k;
            break;

        case 'l':
            setPosition = l;
            break;

        case 'm':
            setPosition = m;
            break;

        case 'n':
            setPosition = n;
            break;

        case 'o':
            setPosition = o;
            break;



        case 'p':
            setPosition = p;
            break;

        case 'q':
            setPosition = q;
            break;

        case 'r':
            setPosition = r;
            break;

        case 's':
            setPosition = s;
            break;

        case 't':
            setPosition = t;
            break;

        case 'u':
            setPosition = u;
            break;

        case 'v':
            setPosition = v;
            break; 

        case 'w':
            setPosition = w;
            break;

        case 'x':
            setPosition = x;
            break;

        case 'y':
            setPosition = y;
            break;

        case 'z':
            setPosition = z;
            break;

        case '{':
            setPosition = lcurly;
            break;

        case '|':
            setPosition = vertline;
            break;

        case '}':
            setPosition = rcurly;
            break;

        // case '->':
        //     *pos = n;
        //     break;

        // case '<-':
        //     *pos = o;
        //     break;

        default:
        break;

    }
    *pos = (u32)setPosition;
    return;
}

void LCD_char_send(i8* val, u32 size, u32* pos)
{
    u32 holder = 0;

    for(u32 i = 0; i < size; i++)
    {
        LCD_decode(val[i], &holder);
        pos[i] = holder;
    }

    return;
}

void nibble_split(u8* upper, u8* lower, u8 byte)
{
    *upper = (byte) & 0xF0;
    *lower = (byte  << 4) & 0xF0;
    return;
}
