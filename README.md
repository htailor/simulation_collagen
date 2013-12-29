Collagen Simulation
==============

Partition function calculations for collagen using the Transfer Matrix Method. This calculation produces shear force plots for various lengths of collagen set by the number of residue triplets `N`.

Requirements
============

* Linux OS
* Mathematica (data analysis)

Compiling Requirements
======================

* GCC 4.7
* OpenMP
* Lapack

Compiling
=========

Run the script `COMPILE.sh` to compile. This will create a new binary file called `collagen` in the directory `./Release`. The source code files are located in the ./src directory. 

Instructions
============

The table highlights the parameters needed to run the calculations

| Parameter | Cmd Flag |              Type              |                          Notes                         |
|:---------:|:--------:|:------------------------------:|:------------------------------------------------------:|
| L         | --L      | &lt;int&gt;  or &lt;double&gt; | Specifies the range of dimensionless space             |
| m         | --m      |           &lt;int&gt;          | Sets the size of the transfer matrix                   |
| N         |  N/A     |           &lt;int&gt;          | Sets the number of residue-triplets in the structure   |
| kappa     | --kappa  |         &lt;double&gt;         | Sets the spring constant of the backbones              |
| sigma     | --sigma  |         &lt;double&gt;         | Sets the spring constant of the residue-triplets       |
| umin      | --umin   |           &lt;int&gt;          | Starting position of the extension (number of delta's) |
| umax      | --umax   |           &lt;int&gt;          | End position of the extension (number of delta's)      |

To set the number of residue triplets in a structure edit the file `N.list` to include a set of `N` values. A typical entry would look like this

```
N=4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50
```

When the calculations are run, directories will be created for each `N` containing the calculated free energies and mean axial displacements. The best method to run the calculations is by executing the `run.sh` script. Edit the script to set parameters highlighted in the table and execute at the commnad line. An example of typical values are shown below:

```shell
L=80.1
M=400

KAPPA=1.2
SIGMA=0.00024
KAPPA_SIGMA_R=$(printf %.0f `echo "$KAPPA/$SIGMA" | bc -l`)

UMIN=0
UMAX=150

touch KAPPA_SIGMA_R_$KAPPA_SIGMA_R

# Pass the parameters to the binary file and run in the background
$BINARY_FILE -L $L -m $M --kappa $KAPPA --sigma $SIGMA --umin $UMIN --umax $UMAX > output &
```

After the results are generated, run the mathematica books in the directories to perform the free energy and mean axial displacement analysis. To perform the shear force analysis, execute the `batch_analysis.sh` script from the root directory with a value of eta_b on the command line:

```
$ ./batch_analysis.sh 1.5
```
This script will run the analysis and collate all the data needed to produce the shear force plots against molecular length. The collated data is stored in a newly created `Analysis_` directory with the value of `eta_b` appended to the name. The `batch_analysis.sh` script can be run a few times if you wish to change the value of `eta_b`. Running the mathematica notebook `complete_analysis_clean.nb` after the shear force analysis has completed will plot the data.
