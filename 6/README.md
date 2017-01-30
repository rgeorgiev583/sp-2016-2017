1. cat и след това wc -c за всеки файл
   $ catwc FILE...
   cat преди wc, редът на файловете няма значение

2. tr SET1 SET2 FILE... (редът няма значение)

3. $ gennum N M
   $ sumnum N M
   $ helper FILENO START LENGTH

   gennum създава файловете:
   1: 1 2 3 ... M
   2: M+1 M+2 ... 2M
   ...
   N: (N-1)M+1 (N-1)M+2 ... NM

   sumnum създава файловете:
   1.sum: 1+2+3+...+M
   2.sum: (M+1)+(M+2)+...+2M
   ...
   N.sum: ((N-1)M+1)+((N-1)M+2)+...+NM

   на stdout се извежда общата сума

   helper генерира всеки отделен файл 1, 2, 3, ..., N (ползва се от gennum)
