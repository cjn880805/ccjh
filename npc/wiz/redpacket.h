//redpacket.h
//lanwood 2001-09-29

NPC_BEGIN(CNwiz_redpacket);

void create()
{
    set_name("��Ӯ", "zi ying");
	set("title", "����ʹ��");
	set("gender", "����" );
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	
	set("long",	"�ף�����һ���ô����ʦ��۫�ŵ�һģһ�����Ǻ�..." );
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set_inquiry("����", ask_for_present);
	set_inquiry("Ѱ��", ask_for_mf);
	set_inquiry("ð��", ask_for_maoxian);
	
	set_temp("no_kill", 1);
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
    set("mp_factor", 300);
	
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
    set_skill("literate",500);
    set_skill("cuff", 500);
	
    set_skill("qiankun_danuoyi",500);
    set_skill("jingang_quan",500);
    set_skill("hunyuan_yiqi",500);
	
    map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("cuff", "jingang_quan");
    map_skill("dodge", "qiankun_danuoyi");
	
    prepare_skill("cuff", "jingang_quan");
	
	set_temp("apply/attack", 500);
	set_temp("apply/dodge", 500);
	
	set("chat_chance", 30);
	set("renwu",1);
//	set("�Թ�",1);
	
    //carry_object("yuyi")->wear();
}

virtual char * chat_msg()
{
	CContainer * env = load_room("pk");
	if(!env->query("yw/thing"))
	{
		env->set("yw/thing",1);
		env->add("yw/count",1);
		call_out(do_thing, 7200+random(7200));
	}
	if(query("start"))
	{
		del("start");
		env->set("yw/thing",1);
		env->add("yw/count",1);
		remove_call_out(do_thing);
		call_out(do_thing, 10);
	}
	//���Ѱ���
	if(query("mf"))
	{
		del("mf");
		env->set("free_mf",1);
		remove_call_out(do_open_mf);
		call_out(do_open_mf, 10);
	}
	//PK����
	if(!query("PK�Զ�"))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t); 
		
		int day = newtime->tm_mday;
		if((day%10)==5 && newtime->tm_hour >= 20 && newtime->tm_hour < 21 && query("renwu"))//�Զ�����PK����
		{
			remove_call_out(do_pk);
			call_out(do_pk, 10);
			set("PK�Զ�",1);
		}
		else if(query("pk") )//��ʦ�ֹ�����PK����
		{
			del("pk");
			remove_call_out(do_pk);
			call_out(do_pk, 10);
		}
	}
	return 0;
}

static void do_pk(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = load_room("pk");
	if(!env->query("PK����"))
		env->set("PK����",1);
	me->call_out(do_pk_end, 3600);
	g_Channel.do_channel(&g_Channel, 0, "chat",	"����к�Ȼ���Ʊ��գ��������綼��Ѫ�ȵ���ɫ¢�ǡ��Ʋ��д��������������ֱ��������ÿ���˵Ķ�����:\n$HIR      ������������֪������ϲ�������ɱ���Ȿ���������ԣ��������ڶ���������������ǣ����Ǵ�������ν��������������\n            ���ڣ����Ǿ�������һ�еĹ�����ʧ��������Ƹ����²��ٻ����������˺��Ŀ־塣\n                          ���డ���������ɱ¾�ɡ�����\n");
}

	
static void do_pk_end(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->call_out(do_pk_end2, 300);
	g_Channel.do_channel(&g_Channel, 0, "chat",	"����ÿ���˶���������ɱʱ��������ٴ������ǻ��������:\n$HIR�� �����ǰ�����ʵ������ˣ�лл���Ǿ��ʵı��ݣ��ǳ��������𺳡���\n���ƽ���ɢȥ��\nÿ���˿���������Ѫ�����ͬ�࣬\n���Ž��µĺ�ʬ��Ұ��Ѫ���ɺӣ�\n���Ÿձ��Լ�ɱ���������밮�˵����壬\n����ţ������ţ�Ż���ţ������š���\n");
}

static void do_pk_end2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("PK�Զ�"))
		me->del("PK�Զ�");
	CContainer * env = load_room("pk");
	if(env->query("PK����"))
		env->del("PK����");
}

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * bot;
	CNpc * randomnpc = load_npc("randomnpc");
	switch(random(8))
	{
	case 0:
		me->set_name("Τ����","wei chunhua");
		randomnpc->set_name("�����ο�","bawang piaoke");
		randomnpc->set("index",1);
		me->command("chat 0 $HIR����������ģ���Ȼ������������˿�֮�󲻸�Ǯ�������Ҥ�Ӱ�����λ����ã�˭����ɱ�˱�����л����");
		break;
	case 1:
		me->set_name("������",  "yue wife");
		randomnpc->set_name("�ɻ����","caihua dadao");
		randomnpc->set("index",2);
		me->command("chat 0 $HIR����˵����вɻ�������У���֪��˭�ܽ�֮��ȥ����");
		break;
	case 2:
		me->set_name("Ҷ����", "ye sanniang");
		randomnpc->set_name("�˷���","ren fanzi");
		randomnpc->set("index",3);
		me->command("chat 0 $HIR���ɶ���˷��ӣ������ǿ����ĺ����յ�����ȥ����Ҫ�����Ҳ����Ļ����Ҿͼ�һ������ɱһ������");
		break;
	case 3:
		me->set_name("ժ����", "zhaiyue zi");
		randomnpc->set_name("¹����","lvming zi");
		randomnpc->set("index",4);
		me->command("chat 0 $HIR��¹������Ϊ���������ɵĵ��ӣ���Ȼ��˼��ȡ����������˵Ӣ��������������ɻ������ֽ��俪����ɣ���λ����ͬ�����׷ɱ�����ɱ�����л����");
		break;
	case 4:
		me->set_name("��ʦ̫", "miejin shitai");
		randomnpc->set_name("�����","dadan zei");
		randomnpc->set("index",5);
		me->command("chat 0 $HIR����ҹ�д����͵���һ����֣�͵ȥ����ʦ�����ָ����ɣ���λ����ͬ�������ô��ˣ����Ϊ׷�ر���ʧ���");
		break;
	case 5:
		me->set_name("������", "baixiao sheng");
		randomnpc->set("index",6);
		me->command("chat 0 $HIR���ŵ������ڹ���������Ϲ������������ľ��������΢�����٣���ؼ�����ʵ����֪˭����Ե�ɵ�֮����");
		break;
	case 6:
		me->set_name("Ȫ�ݽ���", "juanzhou jiangjun");
		randomnpc->set("index",7);
		me->command("chat 0 $HIR�����²��ã���һȺ���˴��Ĳ���������ͽͻȻ����Ȫ�ݺ��۵�½��ɱ�Ұ��գ����ҽ��ã���ֹ���˷�ָ��������λ�¸����صĴ���������������");
		me->command("chat 0 $HIR���˰��ͽ�����ո߳����ҿ񱩳��ԣ�Ŀǰ�Ѿ�ɢ�������ݸ��أ������΢�ߣ��мǲ�Ҫ��ǿ����֮��Ҫ��֮���м��мǣ���");
		break;
	case 7:
		me->set_name("����", "feng qi");
		randomnpc->set("index",8);
		me->command("chat 0 $HIR����ɱ����ѽ�����������ܵ�һЩ�ҵ�����͵û�ˣ��Ҳ����ˣ���");
		break;
	}
	if(randomnpc->query("index")!=6 && randomnpc->query("index")!=8 )
	{
		if(randomnpc->query("index")!=7)
			randomnpc->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
		else
		{
			destruct(randomnpc);
			for(int i=0;i<random(20)+10;i++)
			{
				randomnpc = load_npc("pub_wokou1");
				randomnpc->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
			}
		}
	}
	else if(randomnpc->query("index")==6)
	{
		bot=load_item("jiangzhumu");
		bot->move(load_room("����������"));
		destruct(randomnpc);
	}
	else if(randomnpc->query("index")==8)
	{
		static char item[490][20] =
		{				
			"b_jiasha","backleg","38huoqiang","baguafu","baichou","baihongjian","baihongjian","baixiang","baiyi","baojia","baomingdan",
				"baozi","baozi2","basi_shanyao","bduanqun","beixin","belt","biandan","bilinzhen","bilinzhen","birddie","bishou","blackcloth",
				"blade_2","bluecloth","bocai_fentiao","bocai_fentiao","bojuan","bolanxie","boots","btzheng","bu_shoes","bupao","c_jiasha",
				"caidao","caomei","caoxie","chaidao","chanhe_book1","chanhe_book2","chanhe_book3","chanzhang","cheng_cloth","chicken",
				"chicken","choupao","cleansword","cloth","cloth2","color_dress","connie","cuiyu","cuiyu","cwbdao","cycle","cynrobe",
				"dachang","dadao","dadao2","dafu","dagger","dagoubang","dao_cloth","dao_xie","daopaocyan_cloth","diaojiandai","diaopi",
				"doupeng","doupeng2","dress","duanjian","dulonglian","egg","fannaomao","feather","feicui","feihuangshi","female_shoe",
				"female1_cloth","female2_cloth","female3_cloth","female4_cloth","female5_cloth","female6_cloth","female7_cloth",
				"female8_cloth","fengmi","fenshuici","fish","flower_leaf","flower_shoe","fojing100","fojing101","fojing11","fojing20",
				"fojing200","fojing201","fojing21","fork","fotiaoqiang","fu_cloth","fuchen","fumo_dao","furong_huagu","futou","gancheng",
				"gangbiao","gangdao","gangjian","gangzhang","gao","gao3","gao4","gaoyao","geng","goldring","goupi","gourou","gouroutang",
				"green_cloth","greenrobe","greyrobe","guazi","gui_dress","guiling","gunny_shoes","hamigua","hammer","hanyuzhi","haoseshan",
				"hat","hdjiudai","hedinghong","heilongbian","heiyi","heiyugao","honey","hongchouxiaoshan","hu","huaji","huanchunwan",
				"huangshan","hugesword","hui_cloth","hulu2","huoqiang","huotui","huotui2","hupi","huwan","huwan","huyao","huyao","jade_belt",
				"jiandao","jiaohuaji","jiasha","jiaxin_biji","jiedao","jin","jindai","jinduan","jinduan","jingang_zhao","jingxin_san",
				"jinhua","jinhuantoushi","jinlun","jinshe_zhui","jinsijia","jitui","jiudai","jiuhua","jiujiebian","jiuping","jiuping",
				"jiuping2","jiuping2","jjunfu","junfu","junzijian","junzijian","kandao","kaoya","kaoyangtui","kenao","kenao","kuihua",
				"labazhou","labazhou","lace","langyabang","lantiandai","leizhendang","lengyue_baodao","liaochengpao","linboxie","linen",
				"linen","liu_dress","liuli_qiezi","liumai_sword","longquansword","luo_cloth","luo_cloth","luobo","luoshenjin","lvzhuxiao",
				"magcloth","magcloth","magua","magua","mala_doufu","male_shoe","male1_cloth","male1_cloth","male2_cloth","male2_cloth",
				"male3_cloth","male3_cloth","male4_cloth","male4_cloth","male5_cloth","male6_cloth","male6_cloth","male7_cloth",
				"male7_cloth","male8_cloth","male8_cloth","mandao","mangguo","maotan","maotan","map","marry_1","marry_dress","marz","marz",
				"mask","mask","menghan_yao","mian","mian","mingwang_jian","mini_dress","mitao","mixian","mizhitianou","moon_dress","mudao",
				"mugun","mujian","musicbook1","mutang","muyu","muyuchui","nang","necklace","newyear","newyear1","ni_cloth","ni_xie",
				"niupidai","nverhong","p_jiasha","panguanbi","paomo","peanut","ping","pink_cloth","pink_dress","piqiu","pixue","poliquan",
				"pork","puercha","putizi","putongbishou","qi_dress","qiguoji","qimeigun","qin","qing_cloth","qing_cloth","qingcha",
				"qingke_m","qingpao","qingshui_hulu","qingyi","qingyi","qingyi2","qingzugang","qingzuzang","qinjianhun","qun","qunxing_tu",
				"qunxing_tu","qunxing_tu","r_jiasha","red_dress","renshen","renshenguo","rice","rice3","ring","ring_whip","rose","ruanjian",
				"ruanweijia","sanxiaosan","scarf","seng_cloth","seng_xie","senggun","sengmao","sengxie","sha_dress","shajiezhi",
				"shanhu_baicai","shanshen","shebian","shedan","shedangao","shenghuo_ling","shenshe_staff","shepi","sherou","sherou",
				"shezhang","shield","shikuai","shitou","shoe","shoes","shortblade","shortsword","shoutao","shoutao","shouwu","shouzhuo",
				"shrimp","shrimp","shudai","shuikao","shunvjian","shutonggun","shuzhi","shuzhi2","skin","skirt","snowsword","soup","soup",
				"soup2","soup2","suanmei","suji","sun_book","surcoat","suya","sword_2","sword_3","taibaizao","tanghulu","taomujian",
				"tduanqun","tduanqun","tea_leaf","test","test","throw_book","tiancanbaojia","tianxiang_gao","tie_gan","tiebeixin","tiebian",
				"tiedan","tiegun","tiehuwan","tiehuwan","tiehuyao","tiejia","tiejiang","tielianzi","tiepipa","tieqiao","tieshou","tiezhitao",
				"tofu","tongqun","tongqun","tongren","toukui","ttoujin","tudao","tulong_dao","turou","walkingstick","wandao","wangqing_shi",
				"wchangqun","wcloth","wcloth","wdahui","wdahui","weibo","white_robe","whitecloth","whitecloth1","wodao","wuchangdan","wuji1",
				"wuji2","wuji3","wuqing_sword","xblade","xem_sword","xian_cloth","xiantianyu","xiao","xiaoao","xiaren2","xionghuang",
				"xiu_cloth","xiu_scarf","xiuhua","xu_cloth","xu_cloth","xuantiebishou","xuantiesword","xuanwupao","xuedao","xueli","xuelian",
				"xuelian","xuelian2","xxqingxin_san","y_jiasha","yadan","yan_dress","yangbian","yangjing","yangrou","yangxin","yanshuhua",
				"yaochu","yaodai","yaodai","yaoqin","yayi_cloth","ycloth","ycloth","yeerba","yezi","yinguozhu","yinmopao","youlongsword",
				"ytjian","yuchandan","yuchi","yufeng_zhen","yunshenglv","yupei","yuxiao","yuzhu_zhang","zaisheng","zhangmenhuan","zhanyi",
				"zhanyi","zhaohong","zhemei_book1","zhenzhu","zheshan","zwsword","zhifapu","hanyuepai","zhitao","zhitao","zhitao","zhubang",
				"zhuguo","zhujian","zhutou","zhuyebiao","zi_dress","zidiaopifeng","zijianhun","zijinchui","zongzi","zueiyupao",
		};
		char msg[255];
		for(int i=0;i<10;i++)
		{
			bot = load_item((item[random(490)]));
			bot->set("no_clean_up",1);
			int index=random(MAX_ROOM_NUM);
			CContainer * env = load_room(global_room_name[index]);
			bot->move(env);
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s�ƶ�����%s��",bot->name(1),env->querystr("base_name")));
		}
		destruct(randomnpc);
		
	}
	me->set_name("��Ӯ", "zi ying");
	
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("cuff jingang", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
		perform_action("force powerup", 0);
		break;
	}
	
	return 0;
}

void init(CChar * me)
{
	CNpc::init(me);
	
	if( userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	
	if(! who) return;
	
    me->command(snprintf(msg, 255, "say %ld ������������İɣ�", param1));
}

static char * ask_for_mf(CNpc * npc, CChar * who)
{
	CContainer * env = load_room("pk");
	if(env->query("free_mf"))
	{
		if(who->query("balance") < 200000)
			return "��˵Τ��ү�������������Ʊ������������Ҫ���ģ��������ȵ���ׯ���ϸ���ʮ��ɡ�";

		who->add("balance", -200000);
		who->set_temp("mf/pass",2);
		who->move(load_room("����ɽɽ��"));
		message_vision("$n���ֻ���һ��Ȧ��$N��ʱ��һ�����������֡�", who, npc);
	}
	else
	{
		time_t t;	
		time(&t);
		
		if(!who->query("mf/endtime"))
			return "��ʱ�������ܲ���Ѱ�����";
		else if(t > who->query("mf/endtime"))	
			return "��������ʹ��ʱ�䵽�ڡ�";
		else
		{	
			who->set_temp("mf/pass",1);
			who->move(load_room("����ɽɽ��"));
			message_vision("$n���ֻ���һ��Ȧ��$N��ʱ��һ�����������֡�", who, npc);
		}
	}
	return 0;
}

static void do_open_mf(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->call_out(do_close_mf, 3600);
	me->set_name("ΤС��","wei xiaobao");
	me->command("chat 0 $HIR�������ү�Ҹ��ˣ�����ɽ�Ұ��ˣ�һ��ʱ��֮�ڣ�����ү����Ը��ȥ�����ӵģ���ȫ����ͷ�ϣ���");
	me->set_name("��Ӯ", "zi ying");
	me->command("chat 0 $HIR������˵��һ�䣬����Τ��ү��������ɽ�ǿ��������ǣ�����Ʊ������20���С�Ѵ�һ�����˼��˼һ�µģ�Ҫ��������ڵĺ��������ķ������ˣ����¼��£���");

}
	

static void do_close_mf(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	env->del("free_mf");
}

static char * ask_for_maoxian(CNpc * npc, CChar * me)
{
	if(me->query("level")>=120 && npc->query("�Թ�"))
	{
		CContainer * env = load_room("�ƺ�ɳĮ2");
		if(!env->query("open"))
		{
			g_Channel.do_channel(&g_Channel, 0, "chat",	"\n\n$HIC���һ���������ɳĮ�ϳ���һ����ɳ�����У�����ɳ���׷����������䣬��˵�еĸ߲��Թ�����ڴ��ˡ�$HIY\n\n$COM");
			npc->remove_call_out(do_open);
			npc->call_out(do_open, 3);
			npc->remove_call_out(do_close);
			npc->call_out(do_close, 1800);//30���Ӻ�ر�
		}
	}
	return 0;
}

static void do_open(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("�ƺ�ɳĮ2");
	((CRoom *)env)->add_door("�߲��Թ�", "�߲��Թ�", "�ƺ�ɳĮ2");
	env->set("open",1);
}

static void do_close(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("�ƺ�ɳĮ2");
	env->del("open");
	((CRoom *)env)->remove_all_doors();
	((CRoom *)env)->add_door("�ƺ�ɳĮ1", "�ƺ�ɳĮ1", "�ƺ�ɳĮ2");
	((CRoom *)env)->add_door("�ƺ�ʯ��", "�ƺ�ʯ��", "�ƺ�ɳĮ2");
}

static char * ask_for_present(CNpc * npc, CChar * who)
{
	static struct{
		char name[10];
		int year, month, day;
		char gift[10], open_msg[40];
	} holiday[17] =	{
		{"Ԫ��", 0, 1, 1, "", ""},
		{"������", 0, 4, 5, "", ""},
		{"�Ͷ���", 0, 5, 1, "", ""},
		{"�����", 0, 5, 4, "", ""},
		{"��ͯ��", 0, 6, 1, "", ""},
		{"������", 0, 7, 1, "", ""},
		{"������", 0, 8, 1, "", ""},
		{"��ʦ��", 0, 9, 10, "", ""},
		{"�����", 0, 10, 1, "", ""},
		{"���˽�", 0, 2, 14, "�ɿ���", "С�ĵİ����ɿ��������۵�Ʒζ��"},
		{"���˽�", 0, 4, 1, ""},
		{"ʥ����", 0, 12, 24, "ʥ������", "��ʥ������"},
		{"����", 2003, 2, 1, "����", "�����Ҹ��Ĵ�����"},
		{"Ԫ����", 2003, 2, 15, "Ԫ��", "�Ȳ�����������Ԫ��"},
		{"�����", 2003, 6, 4, "����", "ϸ�����ʵĳ�������"},
		{"�����", 2003, 9, 11, "�±�", "ҧ��һ���±�"},
		{"������", 2003, 10, 4, "", ""},
	};
	
	char msg[255];
	
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;
	
	time(&t);
	newtime = localtime(&t); 
	
	int what_day = -1;
	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;
	int year = 1900 + newtime->tm_year;
	int i;
	
	for(i=0; i< 17; i++)
    {  
		if( (! holiday[i].year || year == holiday[i].year)
			&& ( month == holiday[i].month && day == holiday[i].day) )
			what_day = i;		
    }
	
    if(what_day == -1)
	{
		npc->say(snprintf(msg, 255, "������: %d��%d��, ���������ʲô����Ү��", month, day), who);
		npc->SendMenu(who);
		return 0;
	}
	
    if (who->query("combat_exp") < 3000 || who->query("mud_age") < 18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���";
	
    if (who->query("combat_exp") >=3000 ) 
    {
		CMapping * skl = who->query_skills();
		CVector sname;
		int how = 0;
		
		skl->keys(sname);
		
        for(i=0; i< sname.count(); i++)
            if (skl->query(sname[i]) >= 10) how ++;
			
			if(how < 3)
				return "�����ˮƽ����ȥ��һ�������";
	} 
    
	snprintf(msg, 40, "%ld%s", year, holiday[what_day].name);
	
	if(EQUALSTR(who->querystr("goodday_gift"), msg))
		return "ÿ����һ�ݣ���Ҫ��ô̰�ĺò��ã�";
	
	CContainer * ob = load_item("redpacket");
	
	if(holiday[what_day].gift[0])
	{
		ob->set_name(holiday[what_day].gift);
		ob->set("open_msg", holiday[what_day].open_msg);
	}
	
	ob->move(who);
	who->set("goodday_gift", msg);
	
	message_vision(snprintf(msg, 255, "$n˵����%s���֣�\n$n��$N����1��%s��", holiday[what_day].name, ob->name()), who, npc);
	return 0;
}

NPC_END;



