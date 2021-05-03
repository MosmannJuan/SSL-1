ConversionTest: Conversion.o ConversionTest.o
	gcc -o ConversionTest Conversion.o ConversionTest.o -std=c99

Conversion: TablasDeConversion.o Conversion.o
	gcc -o Conversion Conversion.o TablasDeConversion.o -std=c99

Conversion.o: Conversion.c Conversion.h
	gcc -c Conversion.c

ConversionTest.o: ConversionTest.c Conversion.h
	gcc -c ConversionTest.c

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	gcc -c TablasDeConversion.c
