

rm -rf output
mkdir output

(
cd output;
cp ../report.tex ../refs.bib .;
echo test;
pdflatex report.tex;
bibtex report.aux;
pdflatex report.tex;
pdflatex report.tex;

cp report.pdf ..;
)


