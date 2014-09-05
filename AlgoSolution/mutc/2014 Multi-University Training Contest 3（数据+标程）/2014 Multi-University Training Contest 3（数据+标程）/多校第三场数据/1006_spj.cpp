// For HDU
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

const char *ans[] = {"10.472135955000",
"16.944271909999",
"392.957672397000",
"Impossible",
"Impossible",
"433.274428366724",
"498.451710084941",
"Impossible",
"Impossible",
"375.362516721214",
"445.331608315260",
"Impossible",
"15.402107363438",
"16.641201570752",
"Impossible",
"49.008242580568",
"47.752628966864",
"32.219544457293",
"39.629806061251",
"15.560623297837",
"Impossible",
"Impossible",
"42.135961396099",
"18.375201455727",
"24.392493168788",
"37.523642044352",
"39.102885841986",
"Impossible",
"41.840162662383",
"39.048200038120",
"26.157326801330",
"Impossible",
"19.076845219427",
"51.568776039817",
"17.725430892660",
"20.964080018070",
"32.159069426939",
"Impossible",
"21.114168051656",
"54.081116254010",
"26.416137400092",
"17.276935967781",
"3407.680039791725",
"Impossible",
"2613.747254223557",
"3077.408198975290",
"2035.901997371800",
"3333.653681215590",
"3932.855167537540",
"1463.919763455709",
"2186.592576109572",
"3193.383854937039",
"1439.547008363845",
"1573.000237649342",
"2630.570868499467",
"3449.080441851966",
"2251.400659103527",
"Impossible",
"1047.488581792412",
"4141.966983921615",
"3000.332366339922",
"1169.939946962932",
"3183.801505894909",
"936.022405023606",
"2170.643020155266",
"4927.703064267655",
"Impossible",
"2929.016267847907",
"3958.267077171717",
"1268.440066830724",
"1018.479094079464",
"3833.479974863087",
"15340.179833938546",
"20324.513558431863",
"14670.381923642031",
"19484.231381644608",
"20296.062522201380",
"13115.728222647331",
"9427.458407454651"};

int main(int argc, char **argv) {
	for (int i = 0; i < sizeof(ans) / sizeof(ans[0]); ++i) {
		string user_ans, correct_ans;
		if(!(cin >> user_ans))
		{
			puts("WAWAWA");
			return 0;
		}

		correct_ans = ans[i];
		if (correct_ans == "Impossible") {
			if(user_ans == "Impossible") puts("OK");
			else puts("NO");
			continue;
		}

		if (user_ans == "Impossible") {
			puts("NO");
			continue ;
		}
		/*if (user_ans == "Impossible" || correct_ans == "Impossible") {
			if (user_ans != correct_ans) puts("NO"); else puts("OK");
			continue ;
		}*/
		std::stringstream user_ss(user_ans);
		std::stringstream correct_ss(correct_ans);
		double user = 0.0;
		double corr = 0.0;
		user_ss >> user;
		correct_ss >> corr;
		if (min(fabs(user - corr), fabs(user - corr) / corr) < 1e-6) {
			puts("OK");
		} else {
			puts("NO");
		}
	}
	return 0;
}
