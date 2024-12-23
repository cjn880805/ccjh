//wiz_203.h
//zcoya 2002-07-29

NPC_BEGIN(CNwiz_203);

void create()
{
	set_name("����", "wu qing");
	
	set("title", "����ʹ��");
	set("long","������������ʦ��̰�������ʱ���ҿ���ϣ�����ҵ�һ�������ȥ����");
	
	set("icon", young_monk);
	set("per",28);
	
	set("gender", "����");
	set("level", 300);
	set("age", 19);
	
	set("chat_chance", 3);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("hp", 12500);
	set("max_hp", 12500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 250);
	
	set("combat_exp", 1000000);
	
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("unarmed", 150);
	
	set_skill("tangshoudao", 150);
	set_skill("shenzhao_gong", 150);
	set_skill("piaoyibu", 150);
	set_skill("doomsword", 150);
	
	map_skill("unarmed", "tangshoudao");
	map_skill("force", "shenzhao_gong");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");
	
	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	
	set("bigboss",1);
	carry_object("changjian")->wield();
	set("no_kill",1);
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "���������Դ���֪���ڴ�Щʲô���⣡";
	case 1:
        return "����˵��������ȥ�Ƕ�����أ���";
	case 2:
		random_move();
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("����","bai",me);
		AddMenuItem("Ҫ����","liwu",me);
	}
	else if(!strcmp(ask, "bai") )
	{
		say("����Ц������˵����������ã�����ã������Ҳ�ã���",me);
	}
	else if(!strcmp(ask, "liwu") && !query("stop"))
	{
		if(me->query("chunjie/203/ok"))
		{
			say("���������Դ����������´�����һ��������������ˣ������ˣ���",me);
		}
		else if(!me->query("chunjie/203/count") )
		{
			say("���������Դ����������´�����һ��������Ҫ������ף���������������˵����",me);
		}
		else
		{
			say("���������Դ����������´�����һ�����������ٴ򣿹���������������",me);
		}
	}
	SendMenu(me);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(!strcmp(comm, "fight")  )
	{
		if( !me->query("chunjie/203/ok"))
			return do_fight(me);
		else
			return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

int do_fight(CChar * me)
{
	set("max_hp", 12500);
	set("hp", query("max_hp"));
	set("eff_hp", query("max_hp"));
	set("mp", query("max_mp"));
	delete_temp("apply");
	set("combat_exp", 1000000);
	
	me->set_temp("fight_ok", 1);
	Do_BiShi(this, me, "������д�ս��", 20);
	return 1;
}

//���Խ���
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//��ʤ,���ñ��.�ӳٺ���,�Ա��ս��������.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		winner->set_temp("chunjie/203/win", 1);//�����ʤ
		me = winner;
	}
	
	remove_call_out(do_join);
	call_out(do_join, 2, me->object_id(), 30);
}


static void do_join(CContainer * ob, LONG param1, LONG step)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);
	
	if(! me) 
	{
		if(step > 0) npc->call_out(do_join, 2, param1, step - 1);
		return;
	}
	
	if( me->query_temp("chunjie/203/win"))	//��ʤ�Ļ�
	{
		char msg[255];
		CContainer * baowu;
		me->delete_temp("chunjie/203/win");
		tell_object(me,"\n$HIR����е�������ѽ�������������������㣬�Ҳ��������ˣ���");
		
		static char item[490][20] =
		{				
				"b_jiasha",
				"backleg",
				"38huoqiang",
				"baguafu",
				"baichou",
				"baihongjian",
				"baihongjian",
				"baixiang",
				"baiyi",
				"baojia",
				"baomingdan",
				"baozi",
				"baozi2",
				"basi_shanyao",
				"bduanqun",
				"beixin",
				"belt",
				"biandan",
				"bilinzhen",
				"bilinzhen",
				"birddie",
				"bishou",
				"blackcloth",
				"blade_2",
				"bluecloth",
				"bocai_fentiao",
				"bocai_fentiao",
				"bojuan",
				"bolanxie",
				"boots",
				"btzheng",
				"bu_shoes",
				"bupao",
				"c_jiasha",
				"caidao",
				"caomei",
				"caoxie",
				"chaidao",
				"chanhe_book1",
				"chanhe_book2",
				"chanhe_book3",
				"chanzhang",
				"cheng_cloth",
				"chicken",
				"chicken",
				"choupao",
				"cleansword",
				"cloth",
				"cloth2",
				"color_dress",
				"connie",
				"cuiyu",
				"cuiyu",
				"cwbdao",
				"cycle",
				"cynrobe",
				"dachang",
				"dadao",
				"dadao2",
				"dafu",
				"dagger",
				"dagoubang",
				"dao_cloth",
				"dao_xie",
				"daopaocyan_cloth",
				"diaojiandai",
				"diaopi",
				"doupeng",
				"doupeng2",
				"dress",
				"duanjian",
				"dulonglian",
				"egg",
				"fannaomao",
				"feather",
				"feicui",
				"feihuangshi",
				"female_shoe",
				"female1_cloth",
				"female2_cloth",
				"female3_cloth",
				"female4_cloth",
				"female5_cloth",
				"female6_cloth",
				"female7_cloth",
				"female8_cloth",
				"fengmi",
				"fenshuici",
				"fish",
				"flower_leaf",
				"flower_shoe",
				"fojing100",
				"fojing101",
				"fojing11",
				"fojing20",
				"fojing200",
				"fojing201",
				"fojing21",
				"fork",
				"fotiaoqiang",
				"fu_cloth",
				"fuchen",
				"fumo_dao",
				"furong_huagu",
				"futou",
				"gancheng",
				"gangbiao",
				"gangdao",
				"gangjian",
				"gangzhang",
				"gao",
				"gao3",
				"gao4",
				"gaoyao",
				"geng",
				"goldring",
				"goupi",
				"gourou",
				"gouroutang",
				"green_cloth",
				"greenrobe",
				"greyrobe",
				"guazi",
				"gui_dress",
				"guiling",
				"gunny_shoes",
				"hamigua",
				"hammer",
				"hanyuzhi",
				"haoseshan",
				"hat",
				"hdjiudai",
				"hedinghong",
				"heilongbian",
				"heiyi",
				"heiyugao",
				"honey",
				"hongchouxiaoshan",
				"hu",
				"huaji",
				"huanchunwan",
				"huangshan",
				"hugesword",
				"hui_cloth",
				"hulu2",
				"huoqiang",
				"huotui",
				"huotui2",
				"hupi",
				"huwan",
				"huwan",
				"huyao",
				"huyao",
				"jade_belt",
				"jiandao",
				"jiaohuaji",
				"jiasha",
				"jiaxin_biji",
				"jiedao",
				"jin",
				"jindai",
				"jinduan",
				"jinduan",
				"jingang_zhao",
				"jingxin_san",
				"jinhua",
				"jinhuantoushi",
				"jinlun",
				"jinshe_zhui",
				"jinsijia",
				"jitui",
				"jiudai",
				"jiuhua",
				"jiujiebian",
				"jiuping",
				"jiuping",
				"jiuping2",
				"jiuping2",
				"jjunfu",
				"junfu",
				"junzijian",
				"junzijian",
				"kandao",
				"kaoya",
				"kaoyangtui",
				"kenao",
				"kenao",
				"kuihua",
				"labazhou",
				"labazhou",
				"lace",
				"langyabang",
				"lantiandai",
				"leizhendang",
				"lengyue_baodao",
				"liaochengpao",
				"linboxie",
				"linen",
				"linen",
				"liu_dress",
				"liuli_qiezi",
				"liumai_sword",
				"longquansword",
				"luo_cloth",
				"luo_cloth",
				"luobo",
				"luoshenjin",
				"lvzhuxiao",
				"magcloth",
				"magcloth",
				"magua",
				"magua",
				"mala_doufu",
				"male_shoe",
				"male1_cloth",
				"male1_cloth",
				"male2_cloth",
				"male2_cloth",
				"male3_cloth",
				"male3_cloth",
				"male4_cloth",
				"male4_cloth",
				"male5_cloth",
				"male6_cloth",
				"male6_cloth",
				"male7_cloth",
				"male7_cloth",
				"male8_cloth",
				"male8_cloth",
				"mandao",
				"mangguo",
				"maotan",
				"maotan",
				"map",
				"marry_1",
				"marry_dress",
				"marz",
				"marz",
				"mask",
				"mask",
				"menghan_yao",
				"mian",
				"mian",
				"mingwang_jian",
				"mini_dress",
				"mitao",
				"mixian",
				"mizhitianou",
				"moon_dress",
				"mudao",
				"mugun",
				"mujian",
				"musicbook1",
				"mutang",
				"muyu",
				"muyuchui",
				"nang",
				"necklace",
				"newyear",
				"newyear1",
				"ni_cloth",
				"ni_xie",
				"niupidai",
				"nverhong",
				"p_jiasha",
				"panguanbi",
				"paomo",
				"peanut",
				"ping",
				"pink_cloth",
				"pink_dress",
				"piqiu",
				"pixue",
				"poliquan",
				"pork",
				"puercha",
				"putizi",
				"putongbishou",
				"qi_dress",
				"qiguoji",
				"qimeigun",
				"qin",
				"qing_cloth",
				"qing_cloth",
				"qingcha",
				"qingke_m",
				"qingpao",
				"qingshui_hulu",
				"qingyi",
				"qingyi",
				"qingyi2",
				"qingzugang",
				"qingzuzang",
				"qinjianhun",
				"qun",
				"qunxing_tu",
				"qunxing_tu",
				"qunxing_tu",
				"r_jiasha",
				"red_dress",
				"renshen",
				"renshenguo",
				"rice",
				"rice3",
				"ring",
				"ring_whip",
				"rose",
				"ruanjian",
				"ruanweijia",
				"sanxiaosan",
				"scarf",
				"seng_cloth",
				"seng_xie",
				"senggun",
				"sengmao",
				"sengxie",
				"sha_dress",
				"shajiezhi",
				"shanhu_baicai",
				"shanshen",
				"shebian",
				"shedan",
				"shedangao",
				"shenghuo_ling",
				"shenshe_staff",
				"shepi",
				"sherou",
				"sherou",
				"shezhang",
				"shield",
				"shikuai",
				"shitou",
				"shoe",
				"shoes",
				"shortblade",
				"shortsword",
				"shoutao",
				"shoutao",
				"shouwu",
				"shouzhuo",
				"shrimp",
				"shrimp",
				"shudai",
				"shuikao",
				"shunvjian",
				"shutonggun",
				"shuzhi",
				"shuzhi2",
				"skin",
				"skirt",
				"snowsword",
				"soup",
				"soup",
				"soup2",
				"soup2",
				"suanmei",
				"suji",
				"sun_book",
				"surcoat",
				"suya",
				"sword_2",
				"sword_3",
				"taibaizao",
				"tanghulu",
				"taomujian",
				"tduanqun",
				"tduanqun",
				"tea_leaf",
				"test",
				"test",
				"throw_book",
				"tiancanbaojia",
				"tianxiang_gao",
				"tie_gan",
				"tiebeixin",
				"tiebian",
				"tiedan",
				"tiegun",
				"tiehuwan",
				"tiehuwan",
				"tiehuyao",
				"tiejia",
				"tiejiang",
				"tielianzi",
				"tiepipa",
				"tieqiao",
				"tieshou",
				"tiezhitao",
				"tofu",
				"tongqun",
				"tongqun",
				"tongren",
				"toukui",
				"ttoujin",
				"tudao",
				"tulong_dao",
				"turou",
				"walkingstick",
				"wandao",
				"wangqing_shi",
				"wchangqun",
				"wcloth",
				"wcloth",
				"wdahui",
				"wdahui",
				"weibo",
				"white_robe",
				"whitecloth",
				"whitecloth1",
				"wodao",
				"wuchangdan",
				"wuji1",
				"wuji2",
				"wuji3",
				"wuqing_sword",
				"xblade",
				"xem_sword",
				"xian_cloth",
				"xiantianyu",
				"xiao",
				"xiaoao",
				"xiaren2",
				"xionghuang",
				"xiu_cloth",
				"xiu_scarf",
				"xiuhua",
				"xu_cloth",
				"xu_cloth",
				"xuantiebishou",
				"xuantiesword",
				"xuanwupao",
				"xuedao",
				"xueli",
				"xuelian",
				"xuelian",
				"xuelian2",
				"xxqingxin_san",
				"y_jiasha",
				"yadan",
				"yan_dress",
				"yangbian",
				"yangjing",
				"yangrou",
				"yangxin",
				"yanshuhua",
				"yaochu",
				"yaodai",
				"yaodai",
				"yaoqin",
				"yayi_cloth",
				"ycloth",
				"ycloth",
				"yeerba",
				"yezi",
				"yinguozhu",
				"yinmopao",
				"youlongsword",
				"ytjian",
				"yuchandan",
				"yuchi",
				"yufeng_zhen",
				"yunshenglv",
				"yupei",
				"yuxiao",
				"yuzhu_zhang",
				"zaisheng",
				"zhangmenhuan",
				"zhanyi",
				"zhanyi",
				"zhaohong",
				"zhemei_book1",
				"zhenzhu",
				"zheshan",
				"zwsword",
				"zhifapu",
				"hanyuepai",
				"zhitao",
				"zhitao",
				"zhitao",
				"zhubang",
				"zhuguo",
				"zhujian",
				"zhutou",
				"zhuyebiao",
				"zi_dress",
				"zidiaopifeng",
				"zijianhun",
				"zijinchui",
				"zongzi",
				"zueiyupao",
		};
		
		baowu = load_item((item[random(490)]));
		baowu->move(me);
		tell_object(me,snprintf(msg, 255, "����������һ��%s��������Ѿ��ת�ۼ���ܵ�ûӰ�ˡ�",baowu->name(1)));
			
		int index=random(MAX_ROOM_NUM);
		CContainer * env = load_room(global_room_name[index]);
		npc->move(env);
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "�����ƶ�����%s��",env->querystr("base_name")));
	}
	else//ʧ�ܵĻ�
	{
		tell_object(me,"\n$HIR������˱��죺�������棬�����棬һ��Ҳ�����棡��");
	}
	if(me->query("chunjie/203/count")>10)
	{
		me->set("chunjie/203/ok",1);
		me->del("chunjie/203/count");
	}
	else
		me->add("chunjie/203/count",1);
}

virtual void die()
{
	revive(1);
	set("hp", query("max_hp"));
	set("eff_hp", query("max_hp"));
	set("mp", query("max_mp"));

	message_vision( "������Ʋ��������Ѿ��ת�ۼ���ܵ�ûӰ�ˡ�",this);
	
	int index=random(MAX_ROOM_NUM);
	char msg[255];
	CContainer * env = load_room(global_room_name[index]);
	move(env);
	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "�����ƶ�����%s��",env->querystr("base_name")));

}

NPC_END;
