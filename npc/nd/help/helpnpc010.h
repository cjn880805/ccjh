//helpnpc010.h
//����
//George 2001-07-07

NPC_BEGIN(CNhelpnpc010);

void create()
{
	set_name("����", "tiankuige");
	set("title","����������");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 28);
	set("long","��������һ�ѹŽ��������ƺ�����ʲô������");
	set("attitude", "friendly");  
	set("env/wimpy", 100); 
	set_weight(50000000);
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][200]=
	{
		"��������õķ��ء�",
		"һ�����õı��������ֲ��������Ĳ��㡣",
		"��������Ϻ������еı�������֮һ�����������컹��ʹ���߶�ʮ���Ȱ����ǣ�������ս����ѡ�����Ļ꣬ʿ�����ţ����ɷָ ",
		"������ս���е����ı����������е��˿ͣ������еĲ��죬�����е��η�����ϲ�����ķ��ŵ���Щ��Ҳ���ϲ�����ĺ��죬նɱ�������� ",
		"����Ҳ��һ�ֱ�������������������������ΪһЩ�������˲��ݣ����ǰ�����Ȼ��������������Ϊ���������е�һ�֡� ",
		"��Ҫսʤ���ˣ��Լ�������װ��������Ҫ�ġ�"
	};
	static char hua2[2][100]=
	{
		"�����˽�ʲô������",
		"��ʲô�������׵���"
	};
	static char hua3[38][100]=
	{

		"��ƽ��",
		"���齣",
		"�������",
		"�ط罣",
		"��Ѫ��",
		"��Ů��",
		"���ӽ�",
		"���ѩ�轣",
		"���˵�����",
		"��Ȫ��",														//10

		"�޽�",
		"�̽�",
		"������",
		"�׺罣",
		"��ˮ��",
		"���̽�",
		"���߽�",
		"�Ϻ���ľ",
		"ذ��",
		"���콣",															//20

		"����",
		"����",
		"�������䵶",
		"����",
		"ն��",
		"Ѫ��",
		"��������",
		"���±���",
		"��ħ��",
		"����",															//30

		"�����ⵣ",
		"����ͭ��",
		"��������",
		"����",
		"����",
		"����",
		"ʬ��",
		"������"															//38
	};
	static char hua4[38][200]=
	{

		"̫ƽʢ������ǰ�Ļʹ�����ͳһ�õı���Ҳ�ͱ�ɿ��Զ��ⷢ�۵��ˣ����������ñ��������Լ�ֵҲ���ơ� ",
		"����ʦ���ǷŽ������и��������ĺý����������幤ѧԭ����˵�������ָзǳ��á� ",
		"ר��Ϊ�����������Ƶ���������������������֣�����Υ����������徲֮�⡣ ",
		"��˵ÿһ�Ѷ���������ʦ������������ӻ����ı�������Ȼ���ܳ�ħ��֣�����ʮ�����͡� ",
		"ǰ���͸���������ɱ�ı�������˵��Ϊ�������ҳ�֮Ѫ�����껯�̣��������ںܶ��˶�����һ�����ղ�",
		"�ɵ�����������ʦ�����ν�ţ��ݽ�ͷŷ����������Ĵ���һ�Խ�֮һ����Ȼ�����ʵ�����ֹ���������������������Σ�����Ҫ����װ���⽣���˻���������ϲ��ʱ�ֵ�������Ů��Ŀ�⣬�����н��еľ�����Ʒ��",
		"����Ů����һ�ԣ��������ϵ�Ȼ�ܴ�������Լ������������Լ���ò�����𣿸Ͽ�ȥ��취Ūһ�Ѱɣ� ",
		"�Ѿ��кܶ�����ʷ�������������Ĺ��������Ὣ���ڱ��ݽ����ʱ����ʹ����ѱ������������飬�����ޱȡ� ",
		"��˵�������˵����������ұ�����ɵĽ����ھ���һ��ʮ�����У������������淢�ۣ���������������ֵ�� ",
		"������������ԭ������Ȫ������ʦ�������죬ǧ��������ÿһ�Ѷ�Ҫ���������˺���������Ĵ�����ܳ��ۣ�����Щ�������ֺ�ƭǮ����������������ͬ",

		"Ұ���˵�������ɪ��ʯͷ����γ������Ϲ��������ʹ������������������� ",
		"���û�����ֵĶ̽���֪����ʲô�˵��֣���˵���в���һ���������ܣ��������������˶����鲻͸�� ",
		"�ܾ���ǰ��һ���������֣��ھ����˺ܶ�粨������ɽ����Ϊɮ�����ں�������������˵���������ѱ���������һ�Ѿ������������� ",
		"���������ഫ�ı�����Ҳ��֪���Ǻ�ʱ���������� ",
		"��Ȫ����ʦ�����������ʦ֮������Ȫ���еļ�Ʒ�� ",
		"�䵱�ɵ���ɽ֮�����������ࡣ ",
		"���˷����⣬���ɱ��������ħ���������͹���������кܶ��ر����;����˵��ߴﵽ 35 �����ϣ�����ֻ�л��õ��˲��ܷ����䳤���� ",
		"һ��ľ���������ľ���� ",
		"����¹�������ã��书ƽƽ��¹����Я������ذ�׺���һ����������Ϊ¹�����Ļ����⣬��ذ�׹�����û�� ",
		"һ����������ɫ�ʵ��񽣣��޼᲻�ݵ�������������ʱ����ʼ���������£������־�����ұ��������֪���ж��ٱ�����ϵĹ��£����������˶���������Ķ����� ",

		"�����еĵ�֮һ�����ݽ��ڵĸ������죬�䲻��˵�������࣬���ǿ�������Ҳ����˵��Ӧ�ֶ������ˣ����ݹ��˵���� 10 �ꡣ ",
		"���ձ����ڵ�������������ۣ�������ĥ����������ն�������ҹ��ЧӦҲ���ĺܺã�ʵ�����Ƶ�ҵ�Ŀ�ģ��ŷ����Ҳ����дʫ�������ü��ء� ",
		"Ҳ����������Բ���䵶��ʮ�ַ�������˵���Խ�һƬ��ɴ�����Ϊ���룬�����ܽ�һ��������ͷ������Ϊ���롣�Ǻܶ��˶�ϣ���õ�һ�ѵĺö����� ",
		"�й����ϵ��������ֹ������������ϲ�̫���㣬��ȴʮ��ʵ�ã����ձ�����������ͬ���Ľṹ�����ͣ���˫�ֵ��еĹ���֮һ�� ",
		"�й����ز��������м���һ�������б���������ʮ�㣬��ս���������������׵İѵ���װ���������ͷ����������ս����ս�����ˡ� ",
		"�������Ļ���֮������������Ҳ��֪��ɱ�˶����ˣ�ԩ��ı�ʹʹ��������������������������û��ר�ŵĹ����Ǽ���������ʹ�����ġ�",
		"����ֻ֪������������ѵ���ʼ�����Ĵ���һ��������һ��Ͷ�������¡�Ҳ����һ������ѵ��Ĺ��ͣ�����������������ѿֲ����������¼�ʹ��������Զ������������Ͷ�� ",
		"�������к����콣�����Ĵ��������������������ܣ������ʧ�ٶ���ĵ��ϵõ�����õ����֣���������һ���ӳ�ȥ��ʱ�����ʲô�谭�� ",
		"��Ħ֮��������֮����ǧ����������������ɮ���������������ӻ��������ڷ�ħ������ǰ������û�в���սʤ�Ķ����� ",
		"û�������ķ�â��ֻ�����������ƣ�����ɽ�ĸо����׵ĸо�����ĸо���������Ķ��֡���ҫ��������ɡ�ȥ�����ֵı������",

		"���й��ط������������Ϊ��������Ȼ������Ϊ�ⵣ��ʮ�ּ�����ĥ�������нǣ���������һ���������Ҫǿ�öࡣ ",
		"������Ե������ű���֮һ������Ϊһ���޴��ͭ�ˣ�ʹ������������Ż��裬�������˸������â�� ",
		"�Ŵ����������ı�������Ǻܴ����Ķ��������������ȴ��֪��Ϊʲô��˼�Ӳ���������Ҳ��ͬһ�㣬�����������Ч������Ҫ�������ɲ������׵����顣 ",
		"�й���������֮һ���������ݣ��ṹ�������ǽ���һ�����֣����ڵ�����һ�㶼�ǹ�������������졣 ",
		"���ص�ת���ָ���ɵı������������죬����С����ʹ������ס�ֱ����������ת���������׻����Է����أ��������ӷ��������Ѷȡ� ",
		"���ص�ת���ָ���ɵı���������ʮ��Ļƽ���죬����С����ʹ������ס�ֱ����������ת���������׻����Է����أ��������ӷ��������Ѷȡ� ",
		"���صĹ�ͷ��һ�����ò���������� ",
		"��������б�����Ұ�����ǵ��˵�ר������ʹ�Ǳ�������Ҳ�������׶Կ��ľ޴���أ�������ƾ����ս���ϴ����������С������������������������ǡ�֮˵�� "
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<6;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<38;ii++)
		{
			if(!random(3))
			AddMenuItem(hua3[ii], zifu(ii), me);
		}
		SendMenu(me);
		return 1;
	}
	say(hua4[shuzi(ask)],me);
	SendMenu(me);
	return 1;
}
char * zifu(int x)
{
   switch(x)
   {
		case 0:return "0";
		case 1:return "1";
		case 2:return "2";
		case 3:return "3";
		case 4:return "4";
		case 5:return "5";
		case 6:return "6";
		case 7:return "7";
		case 8:return "8";
		case 9:return "9";
		case 10:return "10";
		case 11:return "11";
		case 12:return "12";
		case 13:return "13";
		case 14:return "14";
		case 15:return "15";
		case 16:return "16";
		case 17:return "17";
		case 18:return "18";
		case 19:return "19";
		case 20:return "20";
		case 21:return "21";
		case 22:return "22";
		case 23:return "23";
		case 24:return "24";
		case 25:return "25";
		case 26:return "26";
		case 27:return "27";
		case 28:return "28";
		case 29:return "29";
		case 30:return "30";
		case 31:return "31";
		case 32:return "32";
		case 33:return "33";
		case 34:return "34";
		case 35:return "35";
		case 36:return "36";
		case 37:return "37";
		case 38:return "38";
		default:return "00";
   }
}
int shuzi(char * y)
{
   if(strcmp(y,"0")==0)
	   return 0;
   else if(strcmp(y,"1")==0)
	   return 1;
   else if(strcmp(y,"2")==0)
	   return 2;
   else if(strcmp(y,"3")==0)
	   return 3;
   else if(strcmp(y,"4")==0)
	   return 4;
   else if(strcmp(y,"5")==0)
	   return 5;
   else if(strcmp(y,"6")==0)
	   return 6;
   else if(strcmp(y,"7")==0)
	   return 7;
   else if(strcmp(y,"8")==0)
	   return 8;
   else if(strcmp(y,"9")==0)
	   return 9;
   else if(strcmp(y,"10")==0)
	   return 10;
   else if(strcmp(y,"11")==0)
	   return 11;
   else if(strcmp(y,"12")==0)
	   return 12;
   else if(strcmp(y,"13")==0)
	   return 13;
   else if(strcmp(y,"14")==0)
	   return 14;
   else if(strcmp(y,"15")==0)
	   return 15;
   else if(strcmp(y,"16")==0)
	   return 16;
   else if(strcmp(y,"17")==0)
	   return 17;
   else if(strcmp(y,"18")==0)
	   return 18;
   else if(strcmp(y,"19")==0)
	   return 19;
   else if(strcmp(y,"20")==0)
	   return 20;
   else if(strcmp(y,"21")==0)
	   return 21;
   else if(strcmp(y,"22")==0)
	   return 22;
   else if(strcmp(y,"23")==0)
	   return 23;
   else if(strcmp(y,"24")==0)
	   return 24;
   else if(strcmp(y,"25")==0)
	   return 25;
   else if(strcmp(y,"26")==0)
	   return 26;
   else if(strcmp(y,"27")==0)
	   return 27;
   else if(strcmp(y,"28")==0)
	   return 28;
   else if(strcmp(y,"29")==0)
	   return 29;
   else if(strcmp(y,"30")==0)
	   return 30;
   else if(strcmp(y,"31")==0)
	   return 31;
   else if(strcmp(y,"32")==0)
	   return 32;
   else if(strcmp(y,"33")==0)
	   return 33;
   else if(strcmp(y,"34")==0)
	   return 34;
   else if(strcmp(y,"35")==0)
	   return 35;
   else if(strcmp(y,"36")==0)
	   return 36;
   else if(strcmp(y,"37")==0)
	   return 37;
   else if(strcmp(y,"38")==0)
	   return 38;
   else 
	   return 100;
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s����ô�Ǵ����Ķ����أ�",query_respect(me) ));
	return 0;
}
/*
virtual void die()
{
	revive(1);
//	message_vision("$N��������������˿�����", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") ==10000  && !query("stop"))
	{
		double value = 3;		//3��
		time_t t;	
		time(&t);
		char msg[255];
		if(t > me->query_temp("�Ĳ�"))
		{
			destruct(ob);
			CContainer * baowu = NULL;
			int diff=5;		//�͵ȼ�װ���ļ��ʿ��Ʋ�������ֵԽ�󣬳��ֵļ���ҲԽ��Ĭ��Ϊ4
			int diff_high=5;	//�ߵȼ�װ���ļ��ʿ��Ʋ�������ֵԽС�����ֵļ���ҲԽ��Ĭ��Ϊ5
			int level = random(59)+40;	//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
			int odds=100;		//	�������Ｘ��,����Ϊodds/100
			int count=1000;	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
			int boss=random(3);//����Ƿ���BOSS�� 
			if(random(100)<=odds)
			{
				int mf=random(level)+random(me->query_temp("apply/mf")/20);
				if(mf>level)
					mf=random(level-39)+40;
				if(mf>90 && random(count/100))
					mf=random(46)+40;
				switch(mf)
				{
				case 10:
					if(random(diff))
					{
						static char item[20][20] =
						{				
							"yuchi","egg","caomei","baozi","tanghulu","rice3","qingshui_hulu",
								"peanut","jiudai","jitui","gouroutang","fish","zhutou","hulu2",
								"hu","hdjiudai","caidao","duanjian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(20)]));
					}
					break;
				case 11:
					if(random(diff))
					{
						static char item[19][20] =
						{				
							"flower_leaf","gancheng","kandao","mudao","mugun","mujian","muyu",
								"muyuchui","shikuai","shitou","shuzhi","shuzhi2","tea_leaf","tieqiao",
								"walkingstick","yangbian","yaoqin","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(19)]));
					}
					break;
				case 12:
					if(random(diff))
					{
						static char item[28][20] =
						{				
							"zhitao","zhujian","baichou","baipao","baiyi","bduanqun","beixin","belt",
								"blackcloth","bluecloth","boots","bupao","bu_shoes","cloth","cloth2","connie",
								"cynrobe","doupeng","goupi","greenrobe","green_cloth","greyrobe","guazi",
								"gunny_shoes","heiyi","hongchouxiaoshan","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(28)]));
					}
					break;
				case 13:
					if(random(diff))
					{
						static char item[49][20] =
						{				
							"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
								"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
								"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
								"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
								"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
								"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(49)]));
					}
					break;
				case 14:
					if(random(diff))
					{
						static char item[49][20] =
						{				
							"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
								"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
								"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
								"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
								"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
								"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(49)]));
					}
					break;
				case 15:
					if(random(diff))
					{
						static char item[89][20] =
						{				
							"zongzi","backleg","yangrou","turou","tofu","puercha","paomo","mizhitianou","mala_doufu",
								"furong_huagu","baozi2","mixian","huotui","hamigua","luobo","geng","gao4","shedan",
								"zaisheng","suanmei","niupidai","changbian","changjian","changqiang","chanzhang",
								"dadao2","feihuangshi","fenshuici","fork","fuchen","futou","gangdao","gangjian",
								"gangzhang","hammer","jiandao","mutang","senggun","shebian","shield","shortblade",
								"wandao","wodao","xiuhua","yuxiao","zheshan","zhubang","b_jiasha","changpao","choupao",
								"dao_cloth","doupeng2","hat","huangshan","hui_cloth","hupi","jiasha","junfu","piqiu",
								"qingyi2","sengmao","seng_cloth","shepi","shoe","shoes","shuikao","tiebeixin","toukui",
								"wchangqun","xian_cloth","map","yadan","xiaren2","shanhu_baicai","rice","nang","liuli_qiezi",
								"kaoyangtui","kaoya","jiaxin_biji","gourou","birddie","basi_shanyao","yezi","yangjing",
								"xueli","suya","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(89)]));
					}
					break;
				case 16:
					if(random(diff))
					{
						static char item[34][20] =
						{				
							"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
								"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
								"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
								"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
								"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(34)]));
					}
					break;
				case 17:
					if(random(diff))
					{
						static char item[19][20] =
						{				
							"skirt","y_jiasha","zhaohong","yeerba","qiguoji","jiaohuaji","qingke_m","qingcha",
								"cleansword","hugesword","taomujian","tiegun","tiejiang","tieshou","wuqing_sword",
								"c_jiasha","dachang","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(19)]));
					}
					break;
				case 18:
					if(random(diff))
					{
						static char item[43][20] =
						{				
							"diaopi","jin","r_jiasha","shudai","pork","fotiaoqiang","tiebian","male5_cloth","qingpao",
								"qun","tiejia","xuelian2","fengmi","axe","biandan","dafu","dagger","huaji","ruanjian",
								"yaochu","male_shoe","pixue","sengxie","seng_xie","surcoat","ttoujin","zhenzhu","menghan_yao",
								"xionghuang","chaidao","mandao","putongbishou","snowsword","xiao","zhuyebiao","color_dress",
								"dress","fu_cloth","goldring","gui_dress","jade_belt","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(43)]));
					}
					break;
				case 19:
					if(random(diff))
					{
						static char item[13][20] =
						{				
							"lace","liu_dress","mini_dress","moon_dress","necklace","pink_dress","qi_dress",
								"red_dress","scarf","sha_dress","shouzhuo","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(13)]));
					}
					break;
				case 20:
					if(random(diff))
					{
						static char item[17][20] =
						{				
							"xiu_cloth","xiu_scarf","yan_dress","zi_dress","yangxin","mitao","yuchandan",
								"xxqingxin_san","jingxin_san","caoxie","cycle","dao_xie","female1_cloth","female2_cloth",
								"female3_cloth","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(17)]));
					}
					break;
				case 21:
					if(random(diff))
					{
						static char item[20][20] =
						{				
							"female4_cloth","female5_cloth","female6_cloth","female7_cloth","female8_cloth",
								"female_shoe","flower_shoe","marry_1","marry_dress","yupei","yaopin_1","huoqiang",
								"jiujiebian","qingzugang","rose","shedangao","nverhong","honey","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(20)]));
					}
					break;
				case 22:
					if(random(diff))
					{
						static char item[12][20] =
						{				
							"arrow","qingzuzang","tiedan","xem_sword","yuzhu_zhang","baguafu",
								"ring","heiyugao","tianxiang_gao","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(12)]));
					}
					break;
				case 23:
					if(random(diff))
					{
						static char item[11][20] =
						{				
							"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
								"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(11)]));
					}
					break;
				case 24:
					if(random(diff))
					{
						static char item[11][20] =
						{				
							"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
								"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(11)]));
					}
					break;
				case 25:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 26:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 27:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 28:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 29:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 30:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"youlongsword","yufeng_zhen","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 31:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"hedinghong","shanshen","blade_2","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 32:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 33:
				case 34:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"shenghuo_ling","jinsijia","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(5)]));				
					}
					break;
				case 35:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1",
								"taibaizao",	//̫����
								"zhuguo",
						};
						baowu = load_item((item[random(4)]));				
					}
					break;
				case 36:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"xuedao","ring_whip","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 37:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 38:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"leizhendang","sword_3","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 39:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"longquansword","xuantiesword","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 40:
					if(random(diff))
					{
						static char item[9][20] =
						{				
							"fojing100","fojing101","fojing11","fojing20","fojing200","fojing201","fojing21","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(9)]));
					}
					break;
				case 41:
					if(random(diff))
					{
						static char item[9][20] =
						{				
							"liumai_sword","wuji1","wuji2","wuji3","yaopin_2","shouwu","sanxiaosan","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(9)]));
					}
					break;
				case 42:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 43:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 44:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"jinhua","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 45:
					if(random(diff))
					{
						static char item[8][20] =
						{				
							"38huoqiang",		//�����˻�ǹ
								"diaojiandai",		//С�ɰ������
								"lantiandai",		//�������
								"guiling","jinlun","chanhe_book1","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(8)]));
					}
					break;
				case 46:
					if(random(diff))
					{
						static char item[6][20] =
						{				
							"chanhe_book2","chanhe_book3","musicbook1","yaopin_2","yaopin_1",
								"jinhuantoushi",		//��ͷ��
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 47:
					if(random(diff))
					{
						static char item[7][20] =
						{				
							"skin","throw_book","putizi","yaopin_2","yaopin_1","zhuguo",
								"linboxie",				//�貨Ь
						};
						baowu = load_item((item[random(7)]));
					}
					break;
				case 48:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 49:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"feather","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 50:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_3","yaopin_2","yaopin_1",
								"btzheng",	//BT�廨��
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 51:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"feicui","yaopin_2","yaopin_1",
								"yunshenglv",	//������
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 52:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"zhemei_book1","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 53:
				case 54:
				case 55:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"xuantiebishou",		//����ذ��
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 56:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"qunxing_tu",//Ⱥ����ͼ
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 57:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"shunvjian","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 58:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"sun_book","yaopin_2","yaopin_1",
								"bolanxie",			//��������Ь
								"qunxing_tu",	//Ⱥ����ͼ
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 59:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"qunxing_tu",//Ⱥ����ͼ
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 60:
					if(random(diff))
					{
						static char item[6][20] =
						{				
							"jiuhua","yaopin_2","yaopin_1",
								"haoseshan",		//���Ӻ�ɫ����
								"xiantianyu",		//�������̾���
								"poliquan",			//��������
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 61:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 62:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 63:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"kuihua","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 64:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 65:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"xblade","yaopin_2","yaopin_1","zhuguo",
								"fannaomao",		//����ȫ��ñ
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 66:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"bojuan",
								"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 67:
				case 68:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 69:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"wuchangdan",		//�޳���
								"shajiezhi",		//ɵ����ָ
								"renshen","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 70:
					if(!random(diff_high) && boss)
					{
						static char item[6][20] =
						{				
							"tiancanbaojia",		//��ϱ���
								"lvzhuxiao",			//������
								"bishou","zhifapu","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 71:
					if(!random(diff_high) && boss)
					{
						static char item[5][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"newyear",		//�������
								"newyear1",		//���̴���
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 72:
				case 73:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 74:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"jinshe_zhui","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 75:
					if(!random(diff_high) && boss)
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"zidiaopifeng",		//��������
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 76:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 77:
				case 78:
				case 79:
					if(!random(diff_high))
					{
						static char item[4][20] =
						{				
							"liaochengpao",		//��ȴ��Ե��
								"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;		
				case 80:
					if(!random(mf-80+diff_high) )
					{
						static char item[6][20] =
						{				
							"baixiang","yaopin_2","yaopin_1","zhuguo",
								"dagoubang",		//�����򹷰�
								"luoshenjin",		//���񷽽�
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 81:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 82:
					if(!random(mf-80+diff_high) )
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"yinguozhu",		//�������
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 83:
					if(!random(mf-80+diff_high))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"dulonglian",		//����������
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 84:
				case 85:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"zueiyupao",		//׺����
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 86:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"yanshuhua",		//���״�컨
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 87:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"baojia","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 88:
				case 89:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"qinjianhun",	//����ʯ*��
								
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 90:
					if(!random(mf-80+diff_high))
					{
						static char item[6][20] =
						{				
							"renshenguo","cwbdao","yaopin_2","yaopin_1",
								"zwsword",			//���佣
								"mingwang_jian",	//������
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 91:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","langyabang",
								"shenshe_staff",		//�϶�������
						};
						baowu = load_item((item[random(4)]));
					}	
					break;	
				case 92:
					if(!random(mf-80+diff_high))
					{
						static char item[5][20] =
						{				
							"yaopin_2","yaopin_1",
								
								"zijianhun",		//����ʯ*��
						};
						baowu = load_item((item[random(5)]));
					}	
					break;
				case 93:
				case 94:
				case 95:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"labazhou","yaopin_2","yaopin_1",
								"ruanweijia",		//������⬼�
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 96:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"labazhou","yaopin_2","yaopin_1",
								"zhangmenhuan",		//������ָ��
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 97:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"lengyue_baodao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 98:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[8][20] =
						{				
							"fumo_dao","jingang_zhao","yaopin_2","yaopin_1",
								"yinmopao",		//��ħ��
								"huanchunwan",	//������
								"baomingdan",	//������
								"wangqing_shi",	//����ʯ
						};
						baowu = load_item((item[random(8)]));
					}
					break;
				case 99:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[6][20] =
						{				
							"ytjian",		//���콣
								"tulong_dao",	//������
								"xuanwupao",	//�������
								"hanyuzhi",		//�����ָ
								"yaopin_2","yaopin_1",
								
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				default:
					baowu = load_item("yaopin_2");
					break;
				}
			}
			else
				baowu=load_item("yaopin_1");
			
			if(baowu)
			{
				add("�Ĳ�",1);
				baowu->move(me);
				tell_object(me,snprintf(msg, 255, "������۾�����������������ǰ��һ�����ŵ�ֽ���У�������������һ�����ó�������һ����ԭ����Ȼ��һ��%s��",baowu->name(1)));
			}
			t += (time_t)value;	
			me->set_temp("�Ĳ�",t);
			return 1;
		}
		else
		{
			tell_object(me, "����Ǯ����ô�죬���ŵ㣬��Щ������Щ���ⲻ�ǻ��ڲ������������Ǯ������������... ...");
		}
	}
	return 0;
}
*/
NPC_END;

