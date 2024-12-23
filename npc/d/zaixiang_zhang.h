//张首辅	秦波 2002、5、23

CNpc * random_npc();

NPC_BEGIN(CNzaixiang_zhang);

void create()
{
	set_name("张居中","zhang juzhong");
	set("long", "他是朝廷内阁首辅，权倾朝野。为人重权谋、有胆略、善用人才，看起来城府极深。\n");
	set("title", "内阁首辅");
	set("gender", "男性");
	set("age", 53);
	set("attitude", "peaceful");
	set("icon",41);
	set("per", 38);
	set("str", 500);
	set("dex", 500);
	set("hp", 500000);
	set("max_hp", 500000);
	set("combat_exp", 20000000);
	set_skill("force", 8000);
	set("task_open", 1);	//任务开放
	set("no_kill",1);
	set("no_talk",1);
	set("no_huan",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n笑呵呵对$N说道:愿意在我手下办差吗？", who, me);

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("索要任务", "$0askquest $1", me);
		AddMenuItem("任务报告", "$0report $1", me);
		AddMenuItem("清除任务", "$0fail $1", me);
		if(me->query("zhang/信任")>10000 && me->query("zhang/问题6")&& !me->query("zhang/问题7"))
		{
			AddMenuItem("夺得祖传宝玉", "$0asw7 $1", me);
		}
		else if(me->query("zhang/信任")>5000 && me->query("zhang/问题5")&& !me->query("zhang/问题6"))
		{
			if(!me->query("zhang/renwu6_end"))
				AddMenuItem("刺杀王都指挥", "$0asw6 $1", me);
			else
				AddMenuItem("刺杀王都指挥任务汇报", "$0asw6 $1", me);
		}
		else if(me->query("zhang/信任")>2500 && me->query("zhang/问题4")&& !me->query("zhang/问题5"))
		{
			time_t t;	
			time(&t);
			if((t > me->query("zhang/renwu5_endtime")) && me->query("zhang/renwu5_endtime"))
				AddMenuItem("胁迫御史任务汇报", "$0asw5 $1", me);
			else
				AddMenuItem("胁迫御史毛成龙", "$0asw5 $1", me);	
		}
		else if(me->query("zhang/信任")>2000 && me->query("zhang/问题3")&& !me->query("zhang/问题4"))
			AddMenuItem("保镖调查汇报", "$0asw4 $1", me);
		else if(me->query("zhang/信任")>1500 && me->query("zhang/问题2")&& !me->query("zhang/问题3"))
			AddMenuItem("促膝长谈", "$0asw3 $1", me);
		else if(me->query("zhang/信任")>1000 && me->query("zhang/问题1") && !me->query("zhang/问题2"))
			AddMenuItem("谈书论儒", "$0asw2 $1", me);
		else if(me->query("zhang/信任")>600 &&!me->query("zhang/问题1"))
			AddMenuItem("投入门下", "$0asw1 $1", me);

		SendMenu(me);
		return 1;
	}
	else
	{
		say("嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);			
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
		if(strcmp(comm, "asw1") == 0)
			return do_asw1(me);
		if(strcmp(comm, "asw11") == 0 && me->query("zhang/信任")>600 &&!me->query("zhang/门生"))
			return do_asw11(me);
		if(strcmp(comm, "asw12") == 0 && me->query("zhang/信任")>600 &&!me->query("zhang/门生"))
			return do_asw12(me);
		if(strcmp(comm, "asw13") == 0 && me->query("zhang/信任")>600 &&!me->query("zhang/门生"))
			return do_asw13(me);
		if(strcmp(comm, "asw14") == 0 && me->query("zhang/信任")>600 &&!me->query("zhang/门生"))
			return do_asw14(me);
		if(strcmp(comm, "asw2") == 0 && me->query("zhang/问题1") &&!me->query("zhang/门生"))
			return do_asw2(me);
		if(strcmp(comm, "asw21") == 0 && me->query("zhang/问题1") &&!me->query("zhang/门生"))
			return do_asw21(me);
		if(strcmp(comm, "asw22") == 0 && me->query("zhang/问题1") &&!me->query("zhang/门生"))
			return do_asw22(me);
		if(strcmp(comm, "asw23") == 0 && me->query("zhang/问题1") &&!me->query("zhang/门生"))
			return do_asw23(me);
		if(strcmp(comm, "asw24") == 0 && me->query("zhang/问题1") &&!me->query("zhang/门生"))
			return do_asw24(me);
		if(strcmp(comm, "asw3") == 0 && me->query("zhang/问题2") &&!me->query("zhang/门生"))
			return do_asw3(me);
		if(strcmp(comm, "asw31") == 0 && me->query("zhang/问题2") &&!me->query("zhang/门生"))
			return do_asw31(me);
		if(strcmp(comm, "asw32") == 0 && me->query("zhang/问题2") &&!me->query("zhang/门生"))
			return do_asw32(me);
		if(strcmp(comm, "asw33") == 0 && me->query("zhang/问题2") &&!me->query("zhang/门生"))
			return do_asw33(me);
		if(strcmp(comm, "asw34") == 0 && me->query("zhang/问题2") &&!me->query("zhang/门生"))
			return do_asw34(me);
		if(strcmp(comm, "asw4") == 0 && me->query("zhang/问题3") &&!me->query("zhang/门生"))
			return do_asw4(me);
		if(strcmp(comm, "asw5") == 0 && me->query("zhang/问题4") &&!me->query("zhang/门生"))
		{
			time_t t;	
			time(&t);
			if(me->query("zhang/renwu5_ok")||
				(t > me->query("zhang/renwu5_endtime")) && me->query("zhang/renwu5_endtime"))
				return do_asw5_ok(me);
			else
				return do_asw5(me);
		}
		if(strcmp(comm, "asw6") == 0 && me->query("zhang/问题5") &&!me->query("zhang/门生"))
		{
			if(!me->query("zhang/renwu6_end"))
				return do_asw6(me);
			else
				return do_asw6_ok(me);
		}
		if(strcmp(comm, "asw7") == 0 && me->query("zhang/问题6") &&!me->query("zhang/门生"))
		{
			return do_asw7(me);
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

//返回npc的方位
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(env->query("wiz_room")) return 0;	//巫师房间。
	if(env->query("renwu")) return 0;		//特殊任务房间。
	if(env->query("sleep_room")) return 0;	//休息区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅
	if(EQUALSTR(env->querystr("area"), "野外")) return 0;	//野外场景
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//战斗场景
	if(atoi(env->querystr("owner"))) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_aq(CChar * me)
{
	char msg[255];
	
	static struct {
		char name[40];
		char desc[180];
		char basename[40];
	}monster[13] = {
		{"御史毛成龙", "御史毛成龙最近准备与其他大臣联名参劾我，你立即想办法让他闭嘴。","yushi mao"},
		{"成都提督", "成都提督很久没有到我这里意思意思了，你帮我抽个时间去教教他该怎么做事的。","chengdu tidu"},
		{"通州知县", "通州知县不识抬举，让他把祖传的那块破玉借我看看都不舍得，你知道该怎么去做了吧！","tongzhou zhixian"},
		{"大学士", "传闻有一大学士私下密谋结党，意图反抗圣上与老夫，你去速速了解此事！","daxue shi"},
		{"新进御史", "今日早朝，有一新进御史当面弹劾老夫，竖子辱吾太甚！我不希望再见到此人。","xinjin yushi"},
		{"司礼太监", "司礼太监最近频繁私自出宫，皇上已不再信任此人，着我将其秘密处死，此事就交给你了。","sili taijian"},
		{"地方布政使", "詹事府密报有地方布政使私献妖姬于诸皇亲，此人野心不小，不能留他在世上。","difang buzhoushi"},
		{"福州知府", "据确切消息，福州知府私自开采铜矿，此类硕鼠，你去将他就地正法，不必押解回京。","fuzhou zhifu"},
		{"京卫指挥使", "京卫指挥使已对我渐生异心，不能为我所用之人，便是与我为敌，你应当知道如何去办了吧？","jinwei duzhihuei"},
		{"王都指挥", "据我眼线密报，王都指挥借驻军边境之机，手握重兵，里通外国，此乃国家大患，速速暗杀之！","wang duzhihuei"},
		{"地方按察使", "地方按察使一直于我提拔的门生作对，孰为可恶，你可将之除去。","difang anchashi"},
		{"儒学教授", "有一儒学教授自持令名，刊印反诗诗集，哎，虽然可惜，但还是必须除去。","ruxue jiaoshou"},
		{"锦衣卫副指挥使", "锦衣卫副指挥使竟为外国间谍！老夫不敢相信，却不可不信，但没有证据在手，只有靠你暗杀一途了。","jinyi wei"},
	};
		LONG monster_id;

		if (me->query("combat_exp") < 10000)
			return notify_fail("张首辅道：少年人，不自量力的事还是少做为好……");
		
		if (me->query_temp("zhang/finish"))
			return notify_fail("张首辅道：哦，你已经完成了任务，为何不来向我告之？");
		
		if ( (monster_id = me->query_temp("zhang/doing")) )
		{
			//判断任务是否失败
			CChar * mon = find_npc(monster_id);
			if(! mon)
				return notify_fail("张首辅哼的一声道：你就这么点能耐呀！让你办点事都办不成！");

			const char * area = position_npc(mon);
			if(! area) return notify_fail("张首辅哼的一声道：你就这么点能耐呀！这点小事都做不了！");

			int diff = me->query_temp("zhang/diff");
			tell_object(me, snprintf(msg, 255, "$HIW张首辅道：%s。你还不快去！", monster[diff].desc));
			return 1;
		}
		else if(me->query("zhang/renwu"))	//任务丢失
		{
			return notify_fail("张首辅哼的一声道：你就这么点能耐呀！");
		}
		
		if (me->is_busy())
			return notify_fail("你现在很忙。。。");

	//随机取一个NPC的场景	
	CNpc * npc = random_npc();

	if(! npc) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");
	if(npc == this) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//自己竟然就是妖怪。呵呵。
	if(! living(npc)) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC快不行了。
	if(DIFFERSTR(npc->querystr("race"), "人类") ) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//非人类NPC
	if(npc->query("no_kill")) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//是一般玩家不可能找到的随机怪物
	if(npc->query("mfnpc_lvl")) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//是梦泽山的随机怪物
	
	CContainer * env = npc->environment();

	//现在判断NPC大致的方位
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC没有环境
	if(! area[0]) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "fight") ) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "野外") ) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC在野外。
	if(env->query("renwu") ) return notify_fail("张首辅道：嗯，老夫想让你再去南方走一遭，只是现在时机未到，你先修养几日吧！");	//这个NPC在特殊任务的房间中。

	int diff = random(13);
	npc = load_npc("pub_mafu");
	npc->set_name(snprintf(msg, 255, "%s%s",monster[diff].name,me->id(1)));
	npc->set("long","");
	npc->set("no_kill",1);
	npc->set("owner",me->id(1));
	npc->set("base_name",snprintf(msg, 255, "%s-%s",monster[diff].basename,me->id(1)));
	npc->set("id","chao guan");
	
	npc->set("str", me->query("str")+random(3));
	npc->set("int", me->query("int")+random(3));
	npc->set("con", me->query("con")+random(3));
	npc->set("dex", me->query("dex")+random(3));
	
	npc->set("max_hp",me->query("max_hp")*2);
	npc->set("eff_hp",me->query("max_hp")*2);
	npc->set("hp", me->query("max_hp")*2);
	npc->set("max_mp", me->query("max_mp"));
	npc->set("mp",  me->query("max_mp"));
	npc->set("mp_factor", me->query("mp_factor"));
	npc->set("combat_exp", int(me->query("combat_exp")/2));
	npc->set("level",me->query("level"));

	int i=me->query("level");
	if((me->query("level")<30 && me->query_skill("force", 1) < 110 && me->query_skill("dodge", 1) < 110 && me->query_skill("parry", 1) < 110)|| (me->query("level")>=30 && me->query("level")<60 && me->query_skill("force", 1) < 220 && me->query_skill("dodge", 1) < 220 && me->query_skill("parry", 1) < 220)|| (me->query("level")>=60 && me->query("level")<80 && me->query_skill("force", 1) < 285 && me->query_skill("dodge", 1) < 285 && me->query_skill("parry", 1) < 285) || me->query("level")>=80)
	{
		if(i>110)i=110;
	}
	else
		i=120;

	int lev=2;
	int leveldiff=int(i*lev);
	switch(random(15)+1)
	{
	case 1:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("taiji_shengong", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("tiyunzong", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("taiji_quan", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("taiji_jian", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("taiji_dao", 50+leveldiff);
		npc->set_skill("taoism", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "taiji_shengong");
		npc->map_skill("dodge", "tiyunzong");
		npc->map_skill("unarmed", "taiji_quan");
		npc->map_skill("parry", "taiji_jian");
		npc->map_skill("sword", "taiji_jian");
		npc->map_skill("blade", "taiji_dao");
		break;
	case 2:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("kurong_changong", 50+leveldiff);
		npc->set_skill("tiannan_step", 50+leveldiff);
		npc->set_skill("jinyu_quan", 50+leveldiff);
		npc->set_skill("wuluo_zhang", 50+leveldiff);
		npc->set_skill("duanjia_sword", 50+leveldiff);
		npc->set_skill("sun_finger", 50+leveldiff);
		npc->set_skill("lm_shangyang", 50+leveldiff);	
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "kurong_changong");
		npc->map_skill("dodge", "tiannan_step");
		npc->map_skill("finger", "sun_finger");
		npc->map_skill("cuff", "jinyu_quan");
		npc->map_skill("strike", "wuluo_zhang");
		npc->map_skill("parry", "sun_finger");
		npc->map_skill("sword", "duanjia_sword");
		npc->map_skill("staff", "duanjia_sword");
		
		npc->prepare_skill("cuff", "jinyu_quan");
		npc->prepare_skill("strike", "wuluo_zhang");
		break;
	case 3:
		npc->set_skill("persuading", 50+leveldiff);
		npc->set_skill("throwing", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("mahayana", 50+leveldiff);
		npc->set_skill("buddhism", 50+leveldiff);
		npc->set_skill("jinding_zhang", 50+leveldiff);
		npc->set_skill("tiangang_zhi", 50+leveldiff);
		npc->set_skill("huifeng_jian", 50+leveldiff);
		npc->set_skill("yanxing_dao", 50+leveldiff);
		npc->set_skill("zhutian_bu", 50+leveldiff);
		npc->set_skill("linji_zhuang", 50+leveldiff);
		
		npc->map_skill("force","linji_zhuang");
		npc->map_skill("finger","tiangang_zhi");
		npc->map_skill("dodge","zhutian_bu");
		npc->map_skill("strike","jinding_zhang");
		npc->map_skill("sword","huifeng_jian");
		npc->map_skill("blade","yanxing_dao");
		npc->map_skill("parry","huifeng_jian");
		break;
	case 4:
		npc->set_skill("persuading", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("hand",50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("hamagong", 50+leveldiff);
		npc->set_skill("chanchu_bufa", 50+leveldiff);
		npc->set_skill("shexing_diaoshou", 50+leveldiff);
		npc->set_skill("lingshe_zhangfa", 50+leveldiff);
		npc->set_skill("xunshou_shu",50+leveldiff);
		
		npc->map_skill("force", "hamagong");
		npc->map_skill("dodge", "chanchu_bufa");
		npc->map_skill("unarmed", "shexing_diaoshou");
		npc->map_skill("hand", "shexing_diaoshou");
		npc->map_skill("parry", "lingshe_zhangfa");
		npc->map_skill("staff", "lingshe_zhangfa");
		break;
	case 5:
		npc->set_skill("force", 50+leveldiff);           
		npc->set_skill("huntian_qigong", 50+leveldiff);    
		npc->set_skill("unarmed", 50+leveldiff);           
		npc->set_skill("xianglong_zhang", 50+leveldiff);   
		npc->set_skill("dodge", 50+leveldiff);      	     
		npc->set_skill("xiaoyaoyou", 50+leveldiff);      
		npc->set_skill("parry", 50+leveldiff);           
		npc->set_skill("staff", 50+leveldiff);            
		npc->set_skill("dagou_bang", 50+leveldiff);        
		npc->set_skill("begging", 50+leveldiff);           
		npc->set_skill("xunshou_shu", 50+leveldiff);
		
		npc->map_skill("force", "huntian_qigong");
		npc->map_skill("unarmed", "xianglong_zhang");
		npc->map_skill("dodge", "xiaoyaoyou");
		npc->map_skill("parry", "xianglong_zhang");
		npc->map_skill("staff", "dagou_bang");
		
		npc->prepare_skill("unarmed", "xianglong_zhang");
		break;
	case 6:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("yunv_xinfa", 50+leveldiff);	
		npc->set_skill("seaforce", 50+leveldiff);		
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("yunv_jian", 50+leveldiff);
		npc->set_skill("smithsword",50+leveldiff);	
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("xianyun_bufa", 50+leveldiff);	
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("meinv_quan", 50+leveldiff);    
		npc->set_skill("anranxiaohun_zhang", 50+leveldiff);
		npc->set_skill("tianluo_diwang", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "seaforce");
		npc->map_skill("sword", "smithsword");
		npc->map_skill("dodge", "xianyun_bufa");
		npc->map_skill("parry", "anranxiaohun_zhang");
		npc->map_skill("unarmed", "anranxiaohun_zhang");
		break;
	case 7:
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("zixia_shengong", 50+leveldiff);
		npc->set_skill("poyu_quan", 50+leveldiff);
		npc->set_skill("huashan_sword", 50+leveldiff);
		npc->set_skill("hunyuan_zhang", 50+leveldiff);
		npc->set_skill("lonely_sword", 50+leveldiff);
		npc->set_skill("huashan_shenfa",50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("zhengqijue", 50+leveldiff);
		
		npc->map_skill("cuff", "poyu_quan");
		npc->map_skill("force", "zixia_shengong");
		npc->map_skill("dodge", "huashan_shenfa");
		npc->map_skill("parry", "lonely_sword");
		npc->map_skill("sword", "lonely_sword");
		npc->map_skill("strike", "hunyuan_zhang");
		break;
	case 8:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("hand",50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword",50+leveldiff);
		
		npc->set_skill("zhemei_shou",50+leveldiff);
		npc->set_skill("liuyang_zhang",50+leveldiff);
		npc->set_skill("tianyu_qijian",50+leveldiff);
		npc->set_skill("yueying_wubu",50+leveldiff);
		npc->set_skill("bahuang_gong", 50+leveldiff);
		
		npc->map_skill("force", "bahuang_gong");
		npc->map_skill("strike","liuyang_zhang");
		npc->map_skill("dodge", "yueying_wubu");
		npc->map_skill("unarmed", "liuyang_zhang");
		npc->map_skill("strike","liuyang_zhang");
		npc->map_skill("hand", "zhemei_shou");
		npc->map_skill("parry", "liuyang_zhang");
		npc->map_skill("sword","tianyu_qijian");
		
		npc->prepare_skill("strike","liuyang_zhang");
		npc->prepare_skill("hand","zhemei_shou");
		break;
	case 9:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("jiuyang_shengong", 50+leveldiff);
		npc->set_skill("lingfa", 50+leveldiff);
		npc->set_skill("shenghuo_lingfa", 50+leveldiff);
		npc->set_skill("qiankun_danuoyi", 50+leveldiff);
		npc->set_skill("shenghuo_xinfa", 50+leveldiff);
		
		npc->map_skill("parry", "qiankun_danuoyi");
		npc->map_skill("force", "jiuyang_shengong");
		npc->map_skill("dodge", "qiankun_danuoyi");
		npc->map_skill("lingfa", "shenghuo_lingfa");
		break;
	case 10:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed",50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("finger",50+leveldiff);
		npc->set_skill("literate",50+leveldiff);
		npc->set_skill("taoism",50+leveldiff);
		npc->set_skill("xiantian_qigong", 50+leveldiff);
		npc->set_skill("xiantian_gong", 50+leveldiff);
		npc->set_skill("quanzhen_jianfa",50+leveldiff);  
		npc->set_skill("quanzhen_jian",50+leveldiff);  
		npc->set_skill("jinyan_gong", 50+leveldiff);   
		npc->set_skill("haotian_zhang", 50+leveldiff);   
		npc->set_skill("sun_finger",50+leveldiff); 
		
		npc->map_skill("force", "xiantian_qigong");
		npc->map_skill("sword", "quanzhen_jianfa");
		npc->map_skill("dodge", "jinyan_gong");
		npc->map_skill("parry", "quanzhen_jianfa");
		npc->map_skill("strike", "haotian_zhang");
		npc->map_skill("finger","sun_finger");
		
		npc->prepare_skill("finger","sun_finger");
		npc->prepare_skill("strike","haotian_zhang");
		break;
	case 11:
		npc->set_skill("buddhism", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("claw", 50+leveldiff);
		npc->set_skill("club", 50+leveldiff);
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("hand", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("whip", 50+leveldiff);
		
		npc->set_skill("banruo_zhang", 50+leveldiff);
		npc->set_skill("cibei_dao", 50+leveldiff);
		npc->set_skill("damo_jian", 50+leveldiff);
		npc->set_skill("fengyun_shou", 50+leveldiff);
		npc->set_skill("fumo_jian", 50+leveldiff);
		npc->set_skill("hunyuan_yiqi", 50+leveldiff);
		npc->set_skill("jingang_quan", 50+leveldiff);
		npc->set_skill("longzhua_gong", 50+leveldiff);
		npc->set_skill("luohan_quan", 50+leveldiff);
		npc->set_skill("nianhua_zhi", 50+leveldiff);
		npc->set_skill("pudu_zhang", 50+leveldiff);
		npc->set_skill("qianye_shou", 50+leveldiff);
		npc->set_skill("sanhua_zhang", 50+leveldiff);
		npc->set_skill("riyue_bian", 50+leveldiff);
		npc->set_skill("shaolin_shenfa", 50+leveldiff);
		npc->set_skill("weituo_gun", 50+leveldiff);
		npc->set_skill("wuchang_zhang", 50+leveldiff);
		npc->set_skill("xiuluo_dao", 50+leveldiff);
		npc->set_skill("yingzhua_gong", 50+leveldiff);
		npc->set_skill("yijinjing", 50+leveldiff);
		npc->set_skill("yizhi_chan", 50+leveldiff);
		npc->set_skill("zui_gun", 50+leveldiff);
		
		npc->map_skill("blade", "cibei_dao");
		npc->map_skill("claw", "longzhua_gong");
		npc->map_skill("club", "wuchang_zhang");
		npc->map_skill("cuff", "luohan_quan");
		npc->map_skill("dodge", "shaolin_shenfa");
		npc->map_skill("finger", "yizhi_chan");
		npc->map_skill("force", "yijinjing");
		npc->map_skill("hand", "fengyun_shou");
		npc->map_skill("parry", "nianhua_zhi");
		npc->map_skill("staff", "weituo_gun");
		npc->map_skill("strike", "banruo_zhang");
		npc->map_skill("sword", "fumo_jian");
		npc->map_skill("whip", "riyue_bian");
		
		npc->prepare_skill("finger", "yizhi_chan");
		npc->prepare_skill("strike", "banruo_zhang");
		break;
	case 12:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->set_skill("shenlong_xinfa", 50+leveldiff);
		npc->set_skill("yixingbu", 50+leveldiff);
		npc->set_skill("shenlong_bashi", 50+leveldiff);
		npc->set_skill("huagu_mianzhang", 50+leveldiff);
		npc->set_skill("shedao_qigong", 50+leveldiff);
		
		npc->map_skill("force", "shenlong_xinfa");
		npc->map_skill("dodge", "yixingbu");
		npc->map_skill("unarmed", "shenlong_bashi");
		npc->map_skill("strike", "huagu_mianzhang");
		npc->map_skill("parry", "shedao_qigong");
		npc->map_skill("sword", "shedao_qigong");
		
		npc->prepare_skill("strike", "huagu_mianzhang");
		npc->prepare_skill("unarmed", "shenlong_bashi");
		break;
	case 13:
		npc->set_skill("force", 50+leveldiff);            
		npc->set_skill("claw", 50+leveldiff);              
		npc->set_skill("hand", 50+leveldiff);            
		npc->set_skill("finger", 50+leveldiff);          
		npc->set_skill("unarmed", 50+leveldiff);         
		npc->set_skill("strike", 50+leveldiff);          
		npc->set_skill("leg",50+leveldiff);	           
		npc->set_skill("dodge", 50+leveldiff);           
		npc->set_skill("parry", 50+leveldiff);            
		npc->set_skill("sword", 50+leveldiff);           
		
		npc->set_skill("anying_fuxiang", 50+leveldiff);    
		npc->set_skill("tanzhi_shentong", 50+leveldiff);   
		npc->set_skill("xuanfeng_leg", 50+leveldiff);      
		npc->set_skill("luoying_shenzhang", 50+leveldiff);     
		npc->set_skill("bibo_shengong", 50+leveldiff);     
		npc->set_skill("luoying_shenjian", 50+leveldiff);  
		npc->set_skill("yuxiao_jianfa", 50+leveldiff);       
		npc->set_skill("lanhua_shou", 50+leveldiff);       
		npc->set_skill("qimen_wuxing",50+leveldiff);       
		npc->set_skill("literate", 50+leveldiff);           
		
		npc->map_skill("force"  , "bibo_shengong");
		npc->map_skill("finger" , "tanzhi_shentong");
		npc->map_skill("hand"   , "lanhua_shou");
		npc->map_skill("unarmed", "luoying_shenzhang");
		npc->map_skill("strike", "luoying_shenzhang");
		npc->map_skill("leg", "xuanfeng_leg");
		npc->map_skill("dodge"  , "anying_fuxiang");
		npc->map_skill("parry"  , "tanzhi_shentong");
		npc->map_skill("sword"  , "tanzhi_shentong");
		
		npc->prepare_skill("finger", "tanzhi_shentong");
		npc->prepare_skill("hand", "lanhua_shou");
		break;
	case 14:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("beiming_shengong", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("lingboweibu", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("liuyang_zhang", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("xiaoyao_dao", 50+leveldiff);
		npc->set_skill("zhemei_shou", 50+leveldiff);
		npc->set_skill("hand", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "beiming_shengong");
		npc->map_skill("dodge", "lingboweibu");      
		npc->map_skill("hand", "zhemei_shou");
		npc->map_skill("unarmed", "liuyang_zhang");
		npc->map_skill("parry", "xiaoyao_dao");
		npc->map_skill("blade", "xiaoyao_dao");
		
		npc->prepare_skill("hand","zhemei_shou");
		npc->prepare_skill("unarmed","liuyang_zhang");
		break;
	case 15:
		npc->set_skill("throwing", 50+leveldiff);
		npc->set_skill("feixing_shu", 50+leveldiff);        
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("huagong_dafa", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("zhaixinggong", 50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("xingxiu_duzhang", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("tianshan_zhang", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("sanyin_wugongzhao", 50+leveldiff);
		npc->set_skill("claw", 50+leveldiff);
		npc->set_skill("poison", 50+leveldiff);
		
		npc->map_skill("force", "huagong_dafa");
		npc->map_skill("dodge", "zhaixinggong");
		npc->map_skill("strike", "xingxiu_duzhang");
		npc->map_skill("parry", "feixing_shu");
		npc->map_skill("staff", "tianshan_zhang");
		npc->map_skill("unarmed", "xingxiu_duzhang");
		npc->map_skill("claw", "sanyin_wugongzhao");
		
		npc->prepare_skill("unarmed", "xingxiu_duzhang");
		npc->prepare_skill("claw", "sanyin_wugongzhao");
		break;	
	}
	npc->move(load_room(env->querystr("base_name")));

	me->set_temp("zhang/doing", npc->object_id());
	me->set_temp("zhang/diff", diff);			//难度系数
	me->set_temp("zhang/name", npc->querystr("name"));	

	me->set("zhang/renwu", 1);	//接过任务了。
		
	message_vision(snprintf(msg, 255, "$HIW张首辅对%s说道：%s。如果不出意外，他应该在%s地带。", me->name(),  monster[diff].desc,env->querystr("area")), me);

	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s接杀%s的%s的任务。", me->name(1), env->querystr("base_name"), npc->name(1)));
		
	return 1;

}

int do_f(CChar * me)
{
	
	if(! me->query("zhang/renwu"))
		return notify_fail("张首辅皱眉道：我派你出去办过差吗？");

	if (me->query_temp("zhang/finish"))
			return notify_fail("张首辅道：哦，你已经完成了任务，为何不来向我告之？");
	
	message_vision("$HIY张首辅顿时拉下了笑脸，大叹道：“哎，$N真是不堪大用”。\n张居中对你的信任度下降了5点。", me);
	
	me->receive_wound("hp", me->query("max_hp") / 3, this);
	me->receive_damage("hp", me->query("max_hp") / 2, this);
	me->add("zhang/信任",-5);
	if(me->query("zhang/信任")<0)
		me->del("zhang/信任");
	me->SendState(me);
	
	me->delete_temp("zhang");
	if(me->query("zhang/count")>10)
		me->add_temp("zhang/count",-10);
	else
		me->delete_temp("zhang/count");
	me->del("zhang/renwu");
	return 1;
}


//给经验
void reward_exp(CChar * me)
{
	char msg[255], tmp[40];
	LONG exp = me->query("level");		

	exp = exp * 2;
	
	//exp = exp * (10 + me->query_temp("fool/diff")) / 10;	//难度系数
	exp = exp + random(me->query("level"));	//难度系数

	exp = (random(exp) + exp) / 2;
	exp=exp*(1+me->query_temp("zhang/count")/10);
	if(exp>800)
		exp=random(400)+400;
	me->add_temp("zhang/count",1);
	if(me->query_temp("zhang/count")>60)
		me->set_temp("zhang/count",1);

	me->add("combat_exp", exp);
	me->add("zhang/信任",1);
	int repute=int((random(31)+100)*(10+me->query_temp("zhang/count"))/10);
	me->add("repute",-repute);
	tell_object(me, snprintf(msg, 255, "$HIC你获得了%s点经验、%d点江湖声望！\n张居中对你的信任度增加了1点。", chinese_number(exp, tmp),-repute));

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s完成了杀%s的任务，获得%d经验、%d点江湖声望。", me->name(1), me->querystr_temp("zhang/name"),  exp,-repute));

	me->FlushMyInfo();
}

int do_r(CChar * me)
{
	if(! me->query("zhang/renwu"))
		return notify_fail("张首辅皱眉道：我派你出去办过差吗？");

	if (!me->query_temp("zhang/finish"))
		return notify_fail("张首辅皱眉道：你杀了他？怎么我今日早朝路上还听人说起他活的还很滋润？");
		
	message_vision("$HIG张首辅抚须笑道：好，好，好！$N，差事办的不错，下去休息吧！",me);
	
	reward_exp(me);
	
	me->delete_temp("zhang/finish");
	me->delete_temp("zhang/diff");
	me->delete_temp("zhang/name");
	me->delete_temp("zhang/doing");
	me->del("zhang/renwu");
	me->start_busy(6);
	return 1;
}


int do_asw1(CChar * me)
{
	say("张首辅笑道：“以你的忠心，投入我的门下做个门生也未尝不可。",  me);
	say("我的案几上摆着三本书，是我常看之物。以你看来这三部书你最喜欢的是什么呢？”",  me);
	AddMenuItem("《易经》", "$0asw11 $1", me);//宰相
	AddMenuItem("《资治通鉴》", "$0asw12 $1", me);//文官
	AddMenuItem("《石头记》", "$0asw13 $1", me);//学士
	AddMenuItem("只喜欢绝世武功秘籍", "$0asw14 $1", me);//武将

	SendMenu(me);
	return 1;
}

int do_asw11(CChar * me)
{
	say("张居中脸色一变，惊道：“你果然学究天人，想必《三坟》、《五典》、《八索》、《九丘》无一不通无一不晓。",  me);
	say("不过这几部上古遗书大多早已亡佚。",  me);
	say("现今似乎只有《三坟》中的《易经》得以传世，你可知何处还有古书遗本，可否借予老夫一观？”",  me);
	SendMenu(me);
	me->set("zhang/易经",1);
	return 1;
}

int do_asw12(CChar * me)
{
	say("张居中抚髯长笑，眼角余光似乎已看透了你是个注重现实的人，就在你被觉得的不寒而栗之时，他那充满魅力的嗓音说道：",  me);
	say("“你果然是明白人，古人云‘半部论语治天下’，老夫却认为是‘半部通鉴治天下’，你真乃老夫知音！”",  me);
	say("你不由得心中升起半是崇拜，半是恐惧，应也不是，否也不是，只有唯唯诺诺含糊过去……",  me);
	SendMenu(me);
	me->set("zhang/问题1",2);
	if(me->query_temp("zhang/易经"))me->delete_temp("zhang/易经");
	return 1;
}

int do_asw13(CChar * me)
{
	say("张居中负手踱步，仰天长叹道：“你真乃性情中人，不过这京畿虽然此刻风云际会、藏龙卧虎能容天下志士，却无一个多情种子的立锥之地，你若是看够了京华烟云，还是请回乡吧。”",  me);
	say("说罢拍了拍你的肩，你突然感到一种如父亲般的温暖，又忽然忆起了了远方的家人，心头一酸掉下泪来……",  me);
	SendMenu(me);
	if(me->query_temp("zhang/易经"))me->delete_temp("zhang/易经");
	return 1;
}

int do_asw14(CChar * me)
{
	say("张居中昂首哈哈大笑，揣着气说：“你果然是一心向武，但你放心，老夫最仰慕的就是你这种豪爽气节。只要你的一身武艺可为老夫所用，荣华富贵享之不尽。”",  me);
	SendMenu(me);
	me->set("zhang/问题1",4);
	if(me->query_temp("zhang/易经"))me->delete_temp("zhang/易经");
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("zhang/易经"))	return 0;
	if(DIFFERSTR(ob->querystr("name"), "「八卦」") && DIFFERSTR(ob->querystr("name"), "「河图」") )	return 0;
	destruct(ob);
	say("张居中惊道：“你果真找到了这古书遗本，果真舍得送给老夫？", who);
	who->set("zhang/问题1",1);
	say("张居中对你的信任度增加了40点。",who);
	say("你获得了50000的赏钱，领悟了10000点的官场经验。",who);
	who->add("zhang/信任",150);
	who->add("combat_exp",10000);
	CMoney::Pay_Player(who, 50000);
	who->delete_temp("zhang/易经");
	SendMenu(who);
	return 1;
}

int do_asw2(CChar * me)
{
	say("只见张居中咪起双眼，粘须问道：“既然说到书了，请问书中有何物？”",  me);
	AddMenuItem("书中自有颜如玉", "$0asw21 $1", me);
	AddMenuItem("书中自有黄金屋", "$0asw22 $1", me);
	AddMenuItem("书中自有千钟粟", "$0asw23 $1", me);
	AddMenuItem("书中自有绝世功", "$0asw24 $1", me);
	SendMenu(me);
	return 1;
}

int do_asw21(CChar * me)
{
	if(DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("张居中抚髯长笑，“哦，你可是这样想的？和老夫年轻时想的一样啊。哈哈哈哈……”",  me);
		if(me->querymap("couple"))
		{
			CUser * targetx;
			char idd[255];
			snprintf(idd,255,"%s",me->querystr("couple/id"));
			targetx=find_online(idd);
			if (targetx)
			{
				if(DIFFERSTR(me->querystr("gender"), "女性"))
				{
					say("$HIR你妻子的魅力上升了1点",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				else if(DIFFERSTR(me->querystr("gender"), "男性"))
				{
					say("$HIR你丈夫的魅力上升了1点",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
			}
			else
			{
				targetx = add_user();
				targetx->set("id", me->querystr("couple/id"));
				targetx->LoadFromServer();
				
				if(DIFFERSTR(me->querystr("gender"), "女性"))
				{
					say("$HIR你妻子的魅力上升了1点",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				else if(DIFFERSTR(me->querystr("gender"), "男性"))
				{
					say("$HIR你丈夫的魅力上升了1点",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				targetx->Save();
			}
			
		}
		else if(EQUALSTR(me->querystr("class"), "bonze"))
		{
			say("张居中皱眉道，“怎么你身在红尘外,还迷恋这付臭皮囊么？”",  me);
			say("$HIR你的魅力下降了3点",me);
			me->add("per",-3);
			me->set("zhang/降低魅力",3);
			if(me->query("per")>1)
				me->set("per",1);
		}
	}
	SendMenu(me);
	me->set("zhang/问题2",1);
	return 1;
}

int do_asw22(CChar * me)
{
	say("张居中沉思半响道，“嗯，宋真宗在劝学文中此一说也过于直白了。皇帝啊，也太不给读书人留面子了。此言应仔细斟酌”",  me);
	SendMenu(me);
	me->set("zhang/问题2",2);
	return 1;
}

int do_asw23(CChar * me)
{
	say("张居中抚髯长笑，“哈哈，那倒是。千钟粟、稻粱谋自可由书中求到。”",  me);
	SendMenu(me);
	me->set("zhang/问题2",3);
	return 1;
}

int do_asw24(CChar * me)
{
	say("张居中抚髯长笑，说道：“你这武痴，真是一句话都离不开武功啊。岂不闻李青莲语：‘身处江湖而心有魏阙’”",  me);
	SendMenu(me);
	me->set("zhang/问题2",4);
	return 1;
}

int do_asw3(CChar * me)
{
	if(!me->query("zhang/问题3"))
	{
		say("张居中扶着你的肩，俩人缓缓坐下,只听他语重心长的说道：“在你心中,老夫到底如何?”",  me);
		AddMenuItem("张大人实乃天下人之典范", "$0asw31 $1", me);
		AddMenuItem("张大人位高权重在下怎敢枉自评价", "$0asw32 $1", me);
		AddMenuItem("......", "$0asw33 $1", me);
		AddMenuItem("张大人对当今皇上似乎太过藐视了", "$0asw34 $1", me);
	}
	else
	{
		switch(me->query("zhang/问题3"))
		{
		case 1:
			say("张居中脸色凝重说道：即是如此，你就先帮老夫办一件差事……事成之后，老夫必定重用、提拔你！",me);
			say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
			say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。",me);
			break;
		case 2:
			say("张居中脸色凝重说道：即是如此，你就先帮老夫办一件差事……事成之后，老夫必定对你信任有加！",me);
			say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
			say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。",me);
			break;
		case 3:
			say("张居中面带不快说道：你似乎有口难言啊！老夫也就不勉强了。你就先帮老夫办一件差事吧！",me);
			say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
			say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。",me);
			break;
		case 4:
			say("张居中沉思半响道，能够放胆直言，才真正是老父的益友！你就先帮老夫办一件差事吧……事成之后，老父必定对你另眼相看!",me);
			say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
			say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。",me);
			break;
		}
	}
	SendMenu(me);
	return 1;
}

int do_asw31(CChar * me)
{
	say("只听你说道：张大人日理万机为国为民，实乃天下人之典范。在下自小便以张大人为榜样。",me);
	say("张大人虽然初识在下，但却已是在下心头数十年严父良师啊！”",me);
	say("张居中脸色凝重说道：“即是如此，你就先帮老夫办一件差事……事成之后，老夫必定重用、提拔你！",me);
	say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！\n$COM此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。”",me);
	say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。”",me);
	me->set("zhang/问题3",1);
	SendMenu(me);
	return 1;
}

int do_asw32(CChar * me)
{
	say("只听你说道：“张大人自是一人以下，万人以上。位高权重，威严无比，令在下难以直视，在下又怎敢枉自评价张居中呢！”",me);
	say("张居中脸色凝重说道：“即是如此，你就先帮老夫办一件差事……事成之后，老夫必定对你信任有加！",me);
	say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
	say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。”",me);
	me->set("zhang/问题3",2);
	SendMenu(me);
	return 1;
}

int do_asw33(CChar * me)
{
	say("张居中面带不快说道：你似乎有口难言啊！老夫也就不勉强了。你就先帮老夫办一件差事吧！",me);
	say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
	say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。”",me);
	me->set("zhang/问题3",3);
	SendMenu(me);
	return 1;
}

int do_asw34(CChar * me)
{
	say("只听你说道：恕在下直言，张大人对当今皇上似乎太过藐视了，容易招人议论啊。",me);
	say("张居中沉思半响道，“能够放胆直言，才真正是老父的益友！你就先帮老夫办一件差事吧……事成之后，老父必定对你另眼相看!",me);
	say("据报：福建福威镖局最近举动异常，往往运送不明镖货给军队，你化装成镖师去查探查探他们保的是什么镖！",me);
	say("此事关系我朝军队，行事务必小心，且毋泄漏行踪，记得常回来给我汇报。”",me);
	me->set("zhang/问题3",4);
	SendMenu(me);
	return 1;
}

int do_asw4(CChar * me)
{
	if(me->query("zhang/保镖")>=5 &&!me->query("zhang/保镖1"))
	{
		say( "你低声向张居中说道：“大人，目前还没有什么眉目，请给在下多一点时间探查。”",me);
		say("张居中点头道：“好，我相信你的能力，希望早日得传捷报。”",me);
		say("张居中对你的信任度增加了50点。",me);
		me->add("zhang/信任",50);
		me->set("zhang/保镖1",1);
	}
	else if(me->query("zhang/保镖")>=15 && !me->query("zhang/保镖2"))
	{
		say("你低声向张居中说道：“大人，稍微有些线索了，原来这些镖都是皇纲，不过具体来龙去脉还不清楚。",me);
		say( "请给在下多一点时间探查，在下必定能查出来的。”",me);
		say("张居中沉思半响道：“好，有进展了。你干得不错，希望早日真相大白。”",me);
		say("张居中对你的信任度增加了100点。",me);
		me->add("zhang/信任",100);
		me->set("zhang/保镖2",1);
	}
	else if(me->query("zhang/保镖")>=30)
	{
		say("你低声向张居中说道：“大人，原来此镖是皇上用来准备攻打外国的军饷，而目的自然是为了大人您……",me);
		say("张居中脸色凝重说道：“是这样啊……你下去吧，记住此事千万不能跟其他人提起！否则，杀无赦！”",me);
		say("张居中对你的信任度增加了150点。",me);
		say("你获得了50000的赏钱，领悟了10000点的官场经验。",me);
		me->add("combat_exp",10000);
		CMoney::Pay_Player(me, 50000);
		me->add("zhang/信任",150);
		me->del("zhang/保镖");
		me->del("zhang/保镖1");
		me->del("zhang/保镖2");
		me->set("zhang/问题4",1);
		me->UpdateMe();
	}
	else
	{
		say("张居中皱眉道：“你什么都没打听到，回来做什么？",me);
	}
	SendMenu(me);
	return 1;
}

int do_asw5(CChar * me)
{
	if(!me->query_temp("zhang/御史毛成龙"))
	{
		tell_object(me, "张居中面带怒色，道：“有消息报御史毛成龙最近准备与其他大臣联名参劾我，你立即想办法让他闭嘴。”");
		me->set_temp("zhang/御史毛成龙",1);
	}
	else
	{
		tell_object(me, "张居中脸带不快，道：“让个小小御史闭嘴的方法都想不出来？去问问成都的百晓生吧，没用的东西！”");
		me->set_temp("zhang/百晓生",1);
	}
	return 1;
}

int do_asw5_ok(CChar * me)
{
	int exp;
	char msg[255];
	time_t t;	
	time(&t);
	//预防时间过长或过短，造成奖励或惩罚过高
	if(t<me->query("zhang/renwu5_endtime")-3000)
		t=me->query("zhang/renwu5_endtime")-3000;
	else if(t>me->query("zhang/renwu5_endtime")+3000)
		t=me->query("zhang/renwu5_endtime")+3000;
	//完成任务奖励
	if(me->query("zhang/renwu5_ok"))
	{
		int repute;
		switch(me->query("zhang/renwu5_ok"))
		{
		case 1:
			exp=30000+10*(t-me->query("zhang/renwu5_endtime"));
			repute=30000+8*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 2:
			exp=20000+8*(t-me->query("zhang/renwu5_endtime"));
			repute=20000+6*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 3:
			exp=15000+6*(t-me->query("zhang/renwu5_endtime"));
			repute=15000+5*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 4:
			exp=10000+5*(t-me->query("zhang/renwu5_endtime"));
			repute=10000+4*(t-me->query("zhang/renwu5_endtime"));
			break;
		}
		me->add("combat_exp", exp);
		me->add("repute",-repute);
		
		if(t > me->query("zhang/renwu5_endtime"))	
		{
			tell_object(me,"\n$HIY张居中顿时拉下了笑脸，大叹道：“哎，真是不堪大用,办了这点小事居然也要花这么久”。\n张居中对你的信任度下降了100点。");
			me->receive_wound("hp", me->query("max_hp") / 3, this);
			me->receive_damage("hp", me->query("max_hp") / 2, this);
			me->add("zhang/信任",-100);
			if(me->query("zhang/信任")<0)
				me->del("zhang/信任");
			me->SendState(me);
		}
		else
		{
			tell_object(me,"\n$HIG张首辅抚须笑道：“好，好，好！差事办的不错，下去休息吧！”。\n张居中对你的信任度上升了200点。");
			me->add("zhang/信任",200);
		}
		
		tell_object(me, snprintf(msg, 255, "$HIC你完成了胁迫御史毛成龙的任务,获得了%d点经验、%d点江湖声望！", exp,-repute));
		
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "%s完成了胁迫御史毛成龙的任务，获得%d经验、%d点江湖声望。", me->name(1), exp,-repute));
		me->FlushMyInfo();
		
		me->set("zhang/问题5",me->query("zhang/renwu5_ok"));
		me->del("zhang/renwu5");
		me->del("zhang/renwu5_ok");
		me->del("zhang/renwu5_endtime");
		me->delete_temp("zhang");
	}
	//任务失败惩罚
	else
	{
		exp=30000+10*(t-me->query("zhang/renwu5_endtime"));
		if(me->query("combat_exp")<=exp)
			exp=me->query("combat_exp");
		exp=-exp;
		me->add("combat_exp", exp);
		me->reset_level();

		tell_object(me,"$HIY张居中顿时拉下了笑脸，大叹道：“哎，真是不堪大用,”。\n张居中对你的信任度下降了200点。");
		tell_object(me, snprintf(msg, 255, "$HIC你胁迫御史毛成龙的任务失败,经验下降%d点经验！", exp));
		
		me->add("zhang/信任",-200);
		if(me->query("zhang/信任")<0)
			me->del("zhang/信任");
		
		me->set("zhang/问题5",99);
		me->del("zhang/renwu5");
		me->del("zhang/renwu5_ok");
		me->del("zhang/renwu5_endtime");
		me->delete_temp("zhang");
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	return 1;
}

int do_asw6(CChar * me)
{
	if(!me->query_temp("zhang/王都指挥"))
	{
		tell_object(me, "张居中面色沉重，道：“据我眼线密报，王都指挥借驻军边境之机，手握重兵，里通外国，此乃国家大患，速速暗杀之！”");
		me->set_temp("zhang/王都指挥",1);

		time_t t;	
		time(&t);
		double value =3600;//限时60分钟
		t += (time_t)value;	
		if(!me->query("zhang/renwu6_endtime"))
			me->set("zhang/renwu6_endtime",t);
	}
	else
	{
		tell_object(me, "张居中语气凝重说道：“此人拥兵自重已久，手下网罗的能人异士颇多，你须小心应付。”");
		tell_object(me, "张居中拍了拍你的肩膀，轻声道：“早年我曾在其身边安插一名心腹之士，你可如此如此。。。。，与他携手一起剪除此贼。”");
		me->set_temp("zhang/冯力强",1);
	}
	return 1;
}

int do_asw6_ok(CChar * me)
{
	int exp;
	char msg[255];
	time_t t;	
	time(&t);
	//预防时间过长或过短，造成奖励或惩罚过高
	if(t<me->query("zhang/renwu6_endtime")-3200)
		t=me->query("zhang/renwu6_endtime")-3200;
	else if(t>me->query("zhang/renwu6_endtime")+3200)
		t=me->query("zhang/renwu6_endtime")+3200;

	if(me->query("zhang/renwu6_end")==1)
	{
		int repute;
		exp=30000+10*(t-me->query("zhang/renwu6_endtime"));
		repute=30000+8*(t-me->query("zhang/renwu6_endtime"));
		me->add("combat_exp", exp);
		me->add("repute",-repute);
		
		if(t > me->query("zhang/renwu6_endtime"))	
		{
			tell_object(me,"\n$HIY张居中顿时拉下了笑脸，大叹道：“哎，真是不堪大用,办了这点小事居然也要花这么久”。\n张居中对你的信任度下降了150点。");
			me->receive_wound("hp", me->query("max_hp") / 3, this);
			me->receive_damage("hp", me->query("max_hp") / 2, this);
			me->add("zhang/信任",-150);
			if(me->query("zhang/信任")<0)
				me->del("zhang/信任");
			me->SendState(me);
			me->set("zhang/问题6",2);//完成任务超时
		}
		else
		{
			tell_object(me,"\n$HIG张首辅抚须笑道：“好，好，好！差事办的不错，下去休息吧！”。\n张居中对你的信任度上升了250点。");
			me->add("zhang/信任",250);
			me->set("zhang/问题6",1);//按时完成任务
		}
		
		tell_object(me, snprintf(msg, 255, "$HIC你完成了刺杀王都指挥的任务,获得了%d点经验、%d点江湖声望！", exp,-repute));
		
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "%s完成了刺杀王都指挥的任务，获得%d经验、%d点江湖声望。", me->name(1), exp,-repute));
		me->FlushMyInfo();

		me->del("zhang/renwu6_endtime");
		me->del("zhang/renwu6_end");
		me->delete_temp("zhang");
	}
	//任务失败惩罚
	else if(me->query("zhang/renwu6_end")==2)
	{
		exp=30000+10*(t-me->query("zhang/renwu6_endtime"));
		if(me->query("combat_exp")<=exp)
			exp=me->query("combat_exp");
		exp=-exp;
		me->add("combat_exp", exp);
		me->reset_level();

		tell_object(me,"$HIY张居中顿时拉下了笑脸，大叹道：“哎，真是不堪大用,”。\n张居中对你的信任度下降了300点。");
		tell_object(me, snprintf(msg, 255, "$HIC你刺杀王都指挥的任务失败,经验下降%d点经验！", exp));
		
		me->add("zhang/信任",-300);
		if(me->query("zhang/信任")<0)
			me->del("zhang/信任");
		
		me->set("zhang/问题6",3);//任务失败
		me->del("zhang/renwu6_endtime");
		me->del("zhang/renwu6_end");
		me->delete_temp("zhang");

		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	else
	{
		tell_object(me,"$HIY很奇怪的问你，除了作弊，你是怎么做到这一步的？？");
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	return 1;
}

int do_asw7(CChar * me)
{
	tell_object(me, "\n$HIC张居中满面不快，道：“通州知县不识抬举，下月后宫张婕妤生日，皇上着他将祖传的那块宝玉敬献，他竟然推托说已经失窃。”");
	tell_object(me, "$HIC你速去彻查此事，如有藏匿可以欺君之罪当场格杀！”\n");
	me->set_temp("zhang/renwi7_1",1);
	return 1;
}

NPC_END;




