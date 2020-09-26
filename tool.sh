# ΝΕΟΦΥΤΟΥ ΑΝΔΡΕΑΣ 1050044
#Εαν το πλήθος των παραμέτρων είναι 0 τότε θα εμφανίζει το ΑΦΜ
if [ $# -eq 0 ]
then
	echo "1050044"

fi
#ta arguements mou tha exoun arxikes times
user_id=false
epitheta=false
firstnames=false
web=false
metavoli=false
birth_apo=false
birth_mexri=false

#using shift for a 7 arguements
while [ "$1" != "" ]; do
	#statements

if [ $1 == "-f" ]
then
	shift
		file=$1 #onoma arxeiou

elif [ $1 == "-id" ]
	then


   shift
  		user_id=$1 #dexomai to sigkekrimeno id 
  

  elif [ $1 == "--firstnames" ]
  	then
  	shift
		firstnames=true
			
elif [ $1 == "--lastnames" ]
		then
			shift
				epitheta=true
					
elif [ $1 == "--born-since" ]
	then


#imeromineia gennisis
shift
	birth_apo=$1
		
elif [ $1 == "--born-until" ]
	then

	shift
birth_mexri=$1
		
elif [ $1 == "--browsers" ]
	then
	browsers=true
		
elif  [ $1 == "--edit" ]; then
	metavoli=true
	shift
	metavoli_id=$1
	shift
	metavoli_stilis=$1
	shift
	metavoli_timis=$1
	
fi


shift
done
#telos to while

#πρώτη εντολή
#./tool.sh -f sample.dat

#reading the file


# ^^^^^^^^^^^^^a erwtima ^^^^^^^^^^^^^^^^^^
#EKTIPOSI TWN PERIEXOMENWN TOU SAMPLE.DAT XWRIS TA SXOLIA
#ENTOLI ./tool.sh -f sample.dat
if [ $firstnames == false ] \
	 && [ $epitheta == false ] \
	  && [ $user_id == false ]  \
	  && [ $birth_apo == false ] \
	  && [ $birth_mexri == false ] \
	  && [ $web == false ] \
	  && [ $metavoli == false ]; 
	 then

	 sed -n '/^#/!p' $file
	
fi
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ERWTIMA B^^^^^^^^^^^^6^^^^^^^
#EKTIPWSI ONOMATOS EPONYMOU KAI IMEROMINEIAS GENNISIS
#./tool.sh -f <file>  - id <id>
#if [ $user_id != false ];
#then
	
#fi

# ^^^^^^^^^^^^^^^^^^^^^^^^^^3 ERWTIMA^^^^^^^^^^^^^^^^^
#tha emfanizei ola ta firstnames se
#alfavitiki seira ena ana grammi
if [ $firstnames == true ] 
	then
	awk -F"|" '/^[^#]/ {print $3}' $file | sort | uniq # diagrafw  ta comments

fi
#^^^^^^^^^^^^^^^^^^^^^^^^^4 ERWTIMA ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#Tha ektiponi ola ta diakrita eponima tou
#arxeiou se alfavitiki seira
if [ $epitheta == true ] 
	then
	awk -F"|" '/^[^#]/ {print $2}' $file | sort | uniq # diagrafw  ta comments


fi
#^^^^^^^^^^^^^^^^^^^^^ERWTIMA  5 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#THA EMFANIZEI MONO TIS GRAMMES POU ANTISTOIXOUN SE XRISTES 
#POU GENNITIKANE APO DATEa MEXRI DATEb
if [$birth_apo != false] || [$birth_mexri !=  false];
	then
apo_date=$(date -d $birth_apo + "%Y%m%d") #=π.χ 20170119
mexri_date=$(date - d $birth_mexri + "%Y%m%d") #=π.χ 20170119
cat $file | while read line
do
	if [[${line:0:wc - l $file}=="#"]];
		then 
		continue
	fi
	IFS='|'
	read -r -a user <<< "$line"
	birth=${user[5]//-}
	if ["$birth" -ge "$apo_date"]&&["$birth" - le "$mexri_date"];
		then
		IFS=' '
		printf "The users of the specific dates are\n"
		echo $line
	fi
done
fi
#^^^^^^^^^^^^^^^^^^^^^^^^^^ 6 erwtima^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#tha emfanizei olous tous browsers
#se alfavitiki seira
#kai meta ton arithmo twn xristwn pou ton xrisimopoioun
if [$web==true];
	then
	
	done | sort test.txt | uniq -c | sort -n | awk -NF, '{a[$8]++;}END{for(i in a)print i,a[i];}' $file #n=compare according to 
											 #to numerical strings
		#awk
		#tha emfanizei to kathe pedio web browser
		#me to onoma tou kai poses fores emfanistike
fi
#^^^^^^^^^^^^^^^^^^^^^^^^ERWTIMA 7^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#THA ALLAZEI TIN TREXOUSA TIMI ID ME TN 
#VALUE POU THA DINETAI SAN ARGUEMENT
if [$metavoli_timis -ge 2]&&[$metavoli_timis -le 8];
	then 
	before_file=$file
	echo "Proigoumeni morfi arxeio\n"
	echo $before_file

	new_file=`awk - v id=$metavoli_id -v tempa=$arithmos_stilis 'BEGIN{FS=OFS="|"} $1==id{$tempa=value} 1' $file`
	#-v assigns a value to a variable
	#px name=jerry "Name=%s\n", name}
	#Name=jerry
	#FS=OFS" INPUT REDERICTION = OUTPUT REDIRECTION
	echo "$new_file" >$file
fi









	


		
	
	
	

	
	









