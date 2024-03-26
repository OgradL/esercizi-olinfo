#include <stdio.h>
#include <assert.h>

long long sum(int arr[], int N){
	long long a = 0;
	for (int i = 0; i < N; i++){
		a += (long long)arr[i];
	}
	return a;
}

int fast_size = 1000;

long long somma(FILE *f){
	int N;
	
	assert(1 == fscanf(f, "%d", &N));
	
	long long ans = 0;
	int c[fast_size];
	
	int dumb;
	
	while (N >= fast_size){
		N -= fast_size;
//		fscanf(f, "%d%d%d%d%d", &c[0], &c[0], &c[2], &c[3], &c[4]);
		dumb = fscanf(f, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7], &c[8], &c[9], &c[10], &c[11], &c[12], &c[13], &c[14], &c[15], &c[16], &c[17], &c[18], &c[19], &c[20], &c[21], &c[22], &c[23], &c[24], &c[25], &c[26], &c[27], &c[28], &c[29], &c[30], &c[31], &c[32], &c[33], &c[34], &c[35], &c[36], &c[37], &c[38], &c[39], &c[40], &c[41], &c[42], &c[43], &c[44], &c[45], &c[46], &c[47], &c[48], &c[49], &c[50], &c[51], &c[52], &c[53], &c[54], &c[55], &c[56], &c[57], &c[58], &c[59], &c[60], &c[61], &c[62], &c[63], &c[64], &c[65], &c[66], &c[67], &c[68], &c[69], &c[70], &c[71], &c[72], &c[73], &c[74], &c[75], &c[76], &c[77], &c[78], &c[79], &c[80], &c[81], &c[82], &c[83], &c[84], &c[85], &c[86], &c[87], &c[88], &c[89], &c[90], &c[91], &c[92], &c[93], &c[94], &c[95], &c[96], &c[97], &c[98], &c[99], &c[100], &c[101], &c[102], &c[103], &c[104], &c[105], &c[106], &c[107], &c[108], &c[109], &c[110], &c[111], &c[112], &c[113], &c[114], &c[115], &c[116], &c[117], &c[118], &c[119], &c[120], &c[121], &c[122], &c[123], &c[124], &c[125], &c[126], &c[127], &c[128], &c[129], &c[130], &c[131], &c[132], &c[133], &c[134], &c[135], &c[136], &c[137], &c[138], &c[139], &c[140], &c[141], &c[142], &c[143], &c[144], &c[145], &c[146], &c[147], &c[148], &c[149], &c[150], &c[151], &c[152], &c[153], &c[154], &c[155], &c[156], &c[157], &c[158], &c[159], &c[160], &c[161], &c[162], &c[163], &c[164], &c[165], &c[166], &c[167], &c[168], &c[169], &c[170], &c[171], &c[172], &c[173], &c[174], &c[175], &c[176], &c[177], &c[178], &c[179], &c[180], &c[181], &c[182], &c[183], &c[184], &c[185], &c[186], &c[187], &c[188], &c[189], &c[190], &c[191], &c[192], &c[193], &c[194], &c[195], &c[196], &c[197], &c[198], &c[199], &c[200], &c[201], &c[202], &c[203], &c[204], &c[205], &c[206], &c[207], &c[208], &c[209], &c[210], &c[211], &c[212], &c[213], &c[214], &c[215], &c[216], &c[217], &c[218], &c[219], &c[220], &c[221], &c[222], &c[223], &c[224], &c[225], &c[226], &c[227], &c[228], &c[229], &c[230], &c[231], &c[232], &c[233], &c[234], &c[235], &c[236], &c[237], &c[238], &c[239], &c[240], &c[241], &c[242], &c[243], &c[244], &c[245], &c[246], &c[247], &c[248], &c[249], &c[250], &c[251], &c[252], &c[253], &c[254], &c[255], &c[256], &c[257], &c[258], &c[259], &c[260], &c[261], &c[262], &c[263], &c[264], &c[265], &c[266], &c[267], &c[268], &c[269], &c[270], &c[271], &c[272], &c[273], &c[274], &c[275], &c[276], &c[277], &c[278], &c[279], &c[280], &c[281], &c[282], &c[283], &c[284], &c[285], &c[286], &c[287], &c[288], &c[289], &c[290], &c[291], &c[292], &c[293], &c[294], &c[295], &c[296], &c[297], &c[298], &c[299], &c[300], &c[301], &c[302], &c[303], &c[304], &c[305], &c[306], &c[307], &c[308], &c[309], &c[310], &c[311], &c[312], &c[313], &c[314], &c[315], &c[316], &c[317], &c[318], &c[319], &c[320], &c[321], &c[322], &c[323], &c[324], &c[325], &c[326], &c[327], &c[328], &c[329], &c[330], &c[331], &c[332], &c[333], &c[334], &c[335], &c[336], &c[337], &c[338], &c[339], &c[340], &c[341], &c[342], &c[343], &c[344], &c[345], &c[346], &c[347], &c[348], &c[349], &c[350], &c[351], &c[352], &c[353], &c[354], &c[355], &c[356], &c[357], &c[358], &c[359], &c[360], &c[361], &c[362], &c[363], &c[364], &c[365], &c[366], &c[367], &c[368], &c[369], &c[370], &c[371], &c[372], &c[373], &c[374], &c[375], &c[376], &c[377], &c[378], &c[379], &c[380], &c[381], &c[382], &c[383], &c[384], &c[385], &c[386], &c[387], &c[388], &c[389], &c[390], &c[391], &c[392], &c[393], &c[394], &c[395], &c[396], &c[397], &c[398], &c[399], &c[400], &c[401], &c[402], &c[403], &c[404], &c[405], &c[406], &c[407], &c[408], &c[409], &c[410], &c[411], &c[412], &c[413], &c[414], &c[415], &c[416], &c[417], &c[418], &c[419], &c[420], &c[421], &c[422], &c[423], &c[424], &c[425], &c[426], &c[427], &c[428], &c[429], &c[430], &c[431], &c[432], &c[433], &c[434], &c[435], &c[436], &c[437], &c[438], &c[439], &c[440], &c[441], &c[442], &c[443], &c[444], &c[445], &c[446], &c[447], &c[448], &c[449], &c[450], &c[451], &c[452], &c[453], &c[454], &c[455], &c[456], &c[457], &c[458], &c[459], &c[460], &c[461], &c[462], &c[463], &c[464], &c[465], &c[466], &c[467], &c[468], &c[469], &c[470], &c[471], &c[472], &c[473], &c[474], &c[475], &c[476], &c[477], &c[478], &c[479], &c[480], &c[481], &c[482], &c[483], &c[484], &c[485], &c[486], &c[487], &c[488], &c[489], &c[490], &c[491], &c[492], &c[493], &c[494], &c[495], &c[496], &c[497], &c[498], &c[499], &c[500], &c[501], &c[502], &c[503], &c[504], &c[505], &c[506], &c[507], &c[508], &c[509], &c[510], &c[511], &c[512], &c[513], &c[514], &c[515], &c[516], &c[517], &c[518], &c[519], &c[520], &c[521], &c[522], &c[523], &c[524], &c[525], &c[526], &c[527], &c[528], &c[529], &c[530], &c[531], &c[532], &c[533], &c[534], &c[535], &c[536], &c[537], &c[538], &c[539], &c[540], &c[541], &c[542], &c[543], &c[544], &c[545], &c[546], &c[547], &c[548], &c[549], &c[550], &c[551], &c[552], &c[553], &c[554], &c[555], &c[556], &c[557], &c[558], &c[559], &c[560], &c[561], &c[562], &c[563], &c[564], &c[565], &c[566], &c[567], &c[568], &c[569], &c[570], &c[571], &c[572], &c[573], &c[574], &c[575], &c[576], &c[577], &c[578], &c[579], &c[580], &c[581], &c[582], &c[583], &c[584], &c[585], &c[586], &c[587], &c[588], &c[589], &c[590], &c[591], &c[592], &c[593], &c[594], &c[595], &c[596], &c[597], &c[598], &c[599], &c[600], &c[601], &c[602], &c[603], &c[604], &c[605], &c[606], &c[607], &c[608], &c[609], &c[610], &c[611], &c[612], &c[613], &c[614], &c[615], &c[616], &c[617], &c[618], &c[619], &c[620], &c[621], &c[622], &c[623], &c[624], &c[625], &c[626], &c[627], &c[628], &c[629], &c[630], &c[631], &c[632], &c[633], &c[634], &c[635], &c[636], &c[637], &c[638], &c[639], &c[640], &c[641], &c[642], &c[643], &c[644], &c[645], &c[646], &c[647], &c[648], &c[649], &c[650], &c[651], &c[652], &c[653], &c[654], &c[655], &c[656], &c[657], &c[658], &c[659], &c[660], &c[661], &c[662], &c[663], &c[664], &c[665], &c[666], &c[667], &c[668], &c[669], &c[670], &c[671], &c[672], &c[673], &c[674], &c[675], &c[676], &c[677], &c[678], &c[679], &c[680], &c[681], &c[682], &c[683], &c[684], &c[685], &c[686], &c[687], &c[688], &c[689], &c[690], &c[691], &c[692], &c[693], &c[694], &c[695], &c[696], &c[697], &c[698], &c[699], &c[700], &c[701], &c[702], &c[703], &c[704], &c[705], &c[706], &c[707], &c[708], &c[709], &c[710], &c[711], &c[712], &c[713], &c[714], &c[715], &c[716], &c[717], &c[718], &c[719], &c[720], &c[721], &c[722], &c[723], &c[724], &c[725], &c[726], &c[727], &c[728], &c[729], &c[730], &c[731], &c[732], &c[733], &c[734], &c[735], &c[736], &c[737], &c[738], &c[739], &c[740], &c[741], &c[742], &c[743], &c[744], &c[745], &c[746], &c[747], &c[748], &c[749], &c[750], &c[751], &c[752], &c[753], &c[754], &c[755], &c[756], &c[757], &c[758], &c[759], &c[760], &c[761], &c[762], &c[763], &c[764], &c[765], &c[766], &c[767], &c[768], &c[769], &c[770], &c[771], &c[772], &c[773], &c[774], &c[775], &c[776], &c[777], &c[778], &c[779], &c[780], &c[781], &c[782], &c[783], &c[784], &c[785], &c[786], &c[787], &c[788], &c[789], &c[790], &c[791], &c[792], &c[793], &c[794], &c[795], &c[796], &c[797], &c[798], &c[799], &c[800], &c[801], &c[802], &c[803], &c[804], &c[805], &c[806], &c[807], &c[808], &c[809], &c[810], &c[811], &c[812], &c[813], &c[814], &c[815], &c[816], &c[817], &c[818], &c[819], &c[820], &c[821], &c[822], &c[823], &c[824], &c[825], &c[826], &c[827], &c[828], &c[829], &c[830], &c[831], &c[832], &c[833], &c[834], &c[835], &c[836], &c[837], &c[838], &c[839], &c[840], &c[841], &c[842], &c[843], &c[844], &c[845], &c[846], &c[847], &c[848], &c[849], &c[850], &c[851], &c[852], &c[853], &c[854], &c[855], &c[856], &c[857], &c[858], &c[859], &c[860], &c[861], &c[862], &c[863], &c[864], &c[865], &c[866], &c[867], &c[868], &c[869], &c[870], &c[871], &c[872], &c[873], &c[874], &c[875], &c[876], &c[877], &c[878], &c[879], &c[880], &c[881], &c[882], &c[883], &c[884], &c[885], &c[886], &c[887], &c[888], &c[889], &c[890], &c[891], &c[892], &c[893], &c[894], &c[895], &c[896], &c[897], &c[898], &c[899], &c[900], &c[901], &c[902], &c[903], &c[904], &c[905], &c[906], &c[907], &c[908], &c[909], &c[910], &c[911], &c[912], &c[913], &c[914], &c[915], &c[916], &c[917], &c[918], &c[919], &c[920], &c[921], &c[922], &c[923], &c[924], &c[925], &c[926], &c[927], &c[928], &c[929], &c[930], &c[931], &c[932], &c[933], &c[934], &c[935], &c[936], &c[937], &c[938], &c[939], &c[940], &c[941], &c[942], &c[943], &c[944], &c[945], &c[946], &c[947], &c[948], &c[949], &c[950], &c[951], &c[952], &c[953], &c[954], &c[955], &c[956], &c[957], &c[958], &c[959], &c[960], &c[961], &c[962], &c[963], &c[964], &c[965], &c[966], &c[967], &c[968], &c[969], &c[970], &c[971], &c[972], &c[973], &c[974], &c[975], &c[976], &c[977], &c[978], &c[979], &c[980], &c[981], &c[982], &c[983], &c[984], &c[985], &c[986], &c[987], &c[988], &c[989], &c[990], &c[991], &c[992], &c[993], &c[994], &c[995], &c[996], &c[997], &c[998], &c[999]);
//		printf("ro\n");
		ans += sum(c, fast_size);
	}
	
	for (int i = 0; i < N; i++){
		assert(1 == fscanf(f, "%d", &c[0]));
		ans += (long long)c[0];
	}
	
	return ans;
}

int main() { printf("%lld\n", somma(stdin)); }
