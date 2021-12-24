## ADMEnigma
<sub>Based on an assignment for Masters course: [Advanced Data Management for Data Analysis](https://studiegids.universiteitleiden.nl/courses/98778/advanced-data-management-for-data-analysis) at Leiden University
</sub>


A C++ console application that encodes and decodes several types of comma delimited datasets using five data encoding and decoding techniques.
Results are compared, across various data types, on compression and speed.


### Report
[Link](https://drive.google.com/file/d/1ro8LUEryw1WXrX_beFdVzwrBFuKuVs_N/view?usp=sharing)



 
### Compression Techniques 
<ul>
<li>“bin”: uncompressed binary format </li>
<li>“rle”: run-length encoding</li>
<li>“dic”: dictionary encoding</li></li>
<li>“for”: frame of reference encoding</li>
<li>“dif”: differential encoding</li>
</ul>

### Instructions
<ul>
<li>Navigate in console to /ADMEnigma-master/ADMEnigma </li>
<li>Run makefile: makeandbake to compile and ready the project (g++ compiler required)  </li>
<li>Run program.exe with 5 or 6 commands </li>
  <ul>
<li>    en / de </li>
<li>bin / rle / dic / for / dif </li>
<li>int8 / int16 / int32 / int64 / string </li>
<li>filename  </li>
<li>print output amount (default value 20, use 0 for entire file) </li>
  </ul>
</ul>
