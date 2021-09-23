#include<cstdio>

int cites[201];

int unionSet(int city1,int city2);
int isSameSet(int city1,int city2);
int findRep(int city);

int main(void){
	int numOfCities,numOfPlans;
	scanf("%d %d",&numOfCities,&numOfPlans);
	for(int i=1;i<=numOfCities;i++)
		cites[i]=i;
	for(int i=1;i<=numOfCities;i++){
		for(int j=1;j<=numOfCities;j++){
			int connection;
			scanf("%d",&connection);
			if(connection)
				unionSet(i,j);
		}
	}
	int prevCity;
    	bool isPossible=true;
	scanf("%d",&prevCity);
	for(int i=1;i<numOfPlans;i++){
		int currentCity;
		scanf("%d",&currentCity);
		if(!isSameSet(prevCity,currentCity)){
			isPossible=false;
			break;
		}
	}
	printf(isPossible ? "YES\n" : "NO\n");
	return 0;
}

int unionSet(int city1,int city2){
	return cites[findRep(city1)]=findRep(city2);
}

int isSameSet(int city1,int city2){
	return findRep(city1)==findRep(city2);
}

int findRep(int city){
	if(cites[city]==city)
		return city;
	return cites[city]=findRep(cites[city]);
}
