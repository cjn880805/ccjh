//redpacket.h
//lanwood 2001-09-29

NPC_BEGIN(CNwiz_redpacket);

void create()
{
    set_name("紫赢", "zi ying");
	set("title", "礼物使者");
	set("gender", "男性" );
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	
	set("long",	"咦？这个家伙怎么和巫师紫郢张得一模一样，呵呵..." );
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set_inquiry("礼物", ask_for_present);
	set_inquiry("寻宝", ask_for_mf);
	set_inquiry("冒险", ask_for_maoxian);
	
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
//	set("迷宫",1);
	
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
	//免费寻宝活动
	if(query("mf"))
	{
		del("mf");
		env->set("free_mf",1);
		remove_call_out(do_open_mf);
		call_out(do_open_mf, 10);
	}
	//PK大赛
	if(!query("PK自动"))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t); 
		
		int day = newtime->tm_mday;
		if((day%10)==5 && newtime->tm_hour >= 20 && newtime->tm_hour < 21 && query("renwu"))//自动启动PK大赛
		{
			remove_call_out(do_pk);
			call_out(do_pk, 10);
			set("PK自动",1);
		}
		else if(query("pk") )//巫师手工启动PK大赛
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
	if(!env->query("PK大赛"))
		env->set("PK大赛",1);
	me->call_out(do_pk_end, 3600);
	g_Channel.do_channel(&g_Channel, 0, "chat",	"天空中忽然赤云蔽日，整个世界都被血腥的颜色垄盖。云层中传来混沌的声音，直传到世上每个人的耳朵里:\n$HIR      地球的生物，我们知道你们喜欢自相残杀，这本是你们天性，不过出于对生命和身体的忧虑，你们创造了所谓的善良和文明。\n            现在，我们就让你们一切的顾虑消失，在这红云覆盖下不再会有死亡与伤害的恐惧。\n                          人类啊……尽情的杀戮吧……。\n");
}

	
static void do_pk_end(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->call_out(do_pk_end2, 300);
	g_Channel.do_channel(&g_Channel, 0, "chat",	"正在每个人都沉醉于厮杀时，天空中再次响起那混沌的声音:\n$HIR“ 人类们啊……实验结束了，谢谢你们精彩的表演，非常令我们震撼。”\n红云渐渐散去。\n每个人看着四周鲜血覆体的同类，\n看着脚下的横尸遍野，血流成河，\n看着刚被自己杀死的亲人与爱人的遗体，\n大哭着，痉挛着，呕吐着，颤抖着……\n");
}

static void do_pk_end2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("PK自动"))
		me->del("PK自动");
	CContainer * env = load_room("pk");
	if(env->query("PK大赛"))
		env->del("PK大赛");
}

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * bot;
	CNpc * randomnpc = load_npc("randomnpc");
	switch(random(8))
	{
	case 0:
		me->set_name("韦春花","wei chunhua");
		randomnpc->set_name("霸王嫖客","bawang piaoke");
		randomnpc->set("index",1);
		me->command("chat 0 $HIR“辣块妈妈的，竟然有人在老娘接了客之后不给钱，逛霸王窑子啊！各位老相好，谁把他杀了必有重谢！”");
		break;
	case 1:
		me->set_name("岳夫人",  "yue wife");
		randomnpc->set_name("采花大盗","caihua dadao");
		randomnpc->set("index",2);
		me->command("chat 0 $HIR“听说最近有采花大盗横行，不知有谁能将之除去。”");
		break;
	case 2:
		me->set_name("叶三娘", "ye sanniang");
		randomnpc->set_name("人贩子","ren fanzi");
		randomnpc->set("index",3);
		me->command("chat 0 $HIR“可恶的人贩子，把我那可怜的孩儿拐到哪里去啦？要是再找不到的话，我就见一个孩子杀一个。”");
		break;
	case 3:
		me->set_name("摘月子", "zhaiyue zi");
		randomnpc->set_name("鹿鸣子","lvming zi");
		randomnpc->set("index",4);
		me->command("chat 0 $HIR“鹿鸣子作为我们星宿派的弟子，竟然不思进取，还暗地里说英明神武的星宿老仙坏话，现将其开革出派，各位江湖同道务必追杀，本派必有重谢！”");
		break;
	case 4:
		me->set_name("灭尽师太", "miejin shitai");
		randomnpc->set_name("大胆蟊贼","dadan zei");
		randomnpc->set("index",5);
		me->command("chat 0 $HIR“昨夜有大胆蟊贼偷入我华藏庵，偷去郭祖师遗留手稿若干，诸位武林同道若见得此人，请带为追回本派失物。”");
		break;
	case 5:
		me->set_name("百晓生", "baixiao sheng");
		randomnpc->set("index",6);
		me->command("chat 0 $HIR“闻得有人在关外见到了上古奇树“绛珠玉木”，已是微见花蕾，想必即将结实，不知谁人有缘可得之。”");
		break;
	case 6:
		me->set_name("泉州将军", "juanzhou jiangjun");
		randomnpc->set("index",7);
		me->command("chat 0 $HIR“大事不好，有一群浪人打扮的不明来历匪徒突然在我泉州海港登陆，杀我百姓，淫我姐妹，举止令人发指。还望各位德高望重的大侠出手襄助，”");
		me->command("chat 0 $HIR“此帮匪徒，武艺高超，且狂暴成性，目前已经散入我神州各地，本领低微者，切记不要逞强，遇之切要避之！切记切记！”");
		break;
	case 7:
		me->set_name("凤七", "feng qi");
		randomnpc->set("index",8);
		me->command("chat 0 $HIR“天杀的贼呀，把我辛苦攒的一些家当都给偷没了，我不活了！”");
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
		bot->move(load_room("关外玉柱峰"));
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
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s移动到了%s。",bot->name(1),env->querystr("base_name")));
		}
		destruct(randomnpc);
		
	}
	me->set_name("紫赢", "zi ying");
	
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
	
    me->command(snprintf(msg, 255, "say %ld 你是来拿礼物的吧？", param1));
}

static char * ask_for_mf(CNpc * npc, CChar * who)
{
	CContainer * env = load_room("pk");
	if(env->query("free_mf"))
	{
		if(who->query("balance") < 200000)
			return "虽说韦爵爷今天包场，但门票工本费您还是要出的，您还是先到银庄存上个二十万吧。";

		who->add("balance", -200000);
		who->set_temp("mf/pass",2);
		who->move(load_room("梦泽山山脚"));
		message_vision("$n伸手画了一个圈，$N顿时被一团迷雾所笼罩。", who, npc);
	}
	else
	{
		time_t t;	
		time(&t);
		
		if(!who->query("mf/endtime"))
			return "暂时您还不能参与寻宝活动。";
		else if(t > who->query("mf/endtime"))	
			return "您的邮箱使用时间到期。";
		else
		{	
			who->set_temp("mf/pass",1);
			who->move(load_room("梦泽山山脚"));
			message_vision("$n伸手画了一个圈，$N顿时被一团迷雾所笼罩。", who, npc);
		}
	}
	return 0;
}

static void do_open_mf(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->call_out(do_close_mf, 3600);
	me->set_name("韦小宝","wei xiaobao");
	me->command("chat 0 $HIR“今天爵爷我高兴，梦泽山我包了，一个时辰之内，老少爷儿们愿意去逛趟子的，帐全算我头上！”");
	me->set_name("紫赢", "zi ying");
	me->command("chat 0 $HIR“补充说明一句，今天韦爵爷包场梦泽山是看的起我们，但门票工本费20万的小费大家还是意思意思一下的，要不逢年过节的红包我们真的发不起了，见谅见谅！”");

}
	

static void do_close_mf(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	env->del("free_mf");
}

static char * ask_for_maoxian(CNpc * npc, CChar * me)
{
	if(me->query("level")>=120 && npc->query("迷宫"))
	{
		CContainer * env = load_room("黄河沙漠2");
		if(!env->query("open"))
		{
			g_Channel.do_channel(&g_Channel, 0, "chat",	"\n\n$HIC大地一阵颤抖，大沙漠上出现一个流沙的旋涡，四周沙砾纷纷向中心陷落，传说中的高昌迷宫的入口打开了。$HIY\n\n$COM");
			npc->remove_call_out(do_open);
			npc->call_out(do_open, 3);
			npc->remove_call_out(do_close);
			npc->call_out(do_close, 1800);//30分钟后关闭
		}
	}
	return 0;
}

static void do_open(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("黄河沙漠2");
	((CRoom *)env)->add_door("高昌迷宫", "高昌迷宫", "黄河沙漠2");
	env->set("open",1);
}

static void do_close(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("黄河沙漠2");
	env->del("open");
	((CRoom *)env)->remove_all_doors();
	((CRoom *)env)->add_door("黄河沙漠1", "黄河沙漠1", "黄河沙漠2");
	((CRoom *)env)->add_door("黄河石洞", "黄河石洞", "黄河沙漠2");
}

static char * ask_for_present(CNpc * npc, CChar * who)
{
	static struct{
		char name[10];
		int year, month, day;
		char gift[10], open_msg[40];
	} holiday[17] =	{
		{"元旦", 0, 1, 1, "", ""},
		{"清明节", 0, 4, 5, "", ""},
		{"劳动节", 0, 5, 1, "", ""},
		{"青年节", 0, 5, 4, "", ""},
		{"儿童节", 0, 6, 1, "", ""},
		{"建党日", 0, 7, 1, "", ""},
		{"建军节", 0, 8, 1, "", ""},
		{"教师节", 0, 9, 10, "", ""},
		{"国庆节", 0, 10, 1, "", ""},
		{"情人节", 0, 2, 14, "巧克力", "小心的剥开巧克力，甜蜜的品味着"},
		{"愚人节", 0, 4, 1, ""},
		{"圣诞节", 0, 12, 24, "圣诞礼物", "打开圣诞礼物"},
		{"春节", 2003, 2, 1, "礼物", "满脸幸福的打开礼物"},
		{"元宵节", 2003, 2, 15, "元宵", "迫不及待的吞下元宵"},
		{"端午节", 2003, 6, 4, "粽子", "细嚼慢咽的吃下粽子"},
		{"中秋节", 2003, 9, 11, "月饼", "咬了一口月饼"},
		{"重阳节", 2003, 10, 4, "", ""},
	};
	
	char msg[255];
	
	//检查系统时间
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
		npc->say(snprintf(msg, 255, "现在是: %d月%d日, 今天好象不是什么节日耶！", month, day), who);
		npc->SendMenu(who);
		return 0;
	}
	
    if (who->query("combat_exp") < 3000 || who->query("mud_age") < 18000)
        return "嘿嘿，想用新玩家来骗我，没门！。";
	
    if (who->query("combat_exp") >=3000 ) 
    {
		CMapping * skl = who->query_skills();
		CVector sname;
		int how = 0;
		
		skl->keys(sname);
		
        for(i=0; i< sname.count(); i++)
            if (skl->query(sname[i]) >= 10) how ++;
			
			if(how < 3)
				return "就你的水平？再去练一会儿！。";
	} 
    
	snprintf(msg, 40, "%ld%s", year, holiday[what_day].name);
	
	if(EQUALSTR(who->querystr("goodday_gift"), msg))
		return "每个人一份，不要这么贪心好不好！";
	
	CContainer * ob = load_item("redpacket");
	
	if(holiday[what_day].gift[0])
	{
		ob->set_name(holiday[what_day].gift);
		ob->set("open_msg", holiday[what_day].open_msg);
	}
	
	ob->move(who);
	who->set("goodday_gift", msg);
	
	message_vision(snprintf(msg, 255, "$n说道：%s快乐！\n$n给$N数量1的%s。", holiday[what_day].name, ob->name()), who, npc);
	return 0;
}

NPC_END;



