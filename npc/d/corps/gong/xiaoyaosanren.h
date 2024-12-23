CNpc * random_npc();

NPC_BEGIN(CNcorps_xiaoyaosanren);

void create()
{
	set_name("逍遥散人","xiaoyao sanren");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 18+random(5));
    
	set("per", 18 + random(15));
    set("combat_exp", 100);
	set("no_kill", 1);
	set("infinity", 1);		//不受容量限制
	set("is_user", 1);
	set_weight(50000000);//不可被拾取
	call_out(do_die, 60); //定时存盘
	
}

int do_talk(CChar *me, char * ask)
{
	CNpc::do_talk(me, ask);
	if(me->querymap("corps") && ! me->is_fighting() && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		char msg[255];
		AddMenuItem(snprintf(msg, 255,"向%s领取帮派任务",name()), "$0get_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"向%s汇报帮派任务",name()), "$0report_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"请%s清除帮派任务",name()), "$0fail_renwu $1", me);
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->querymap("corps") && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		if(strcmp(comm, "get_renwu") == 0)
			return do_aq(me);
		if(strcmp(comm, "report_renwu") == 0)
			return do_r(me);
		if(strcmp(comm, "fail_renwu") == 0)
			return do_f(me);
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
	if(env->query("corp")) return 0;	//帮派场景
	if(atoi(env->querystr("owner"))) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

//帮派任务
int do_aq(CChar * me)
{
	char msg[255];

	static struct{
		char name[20], id[20];		//怪物名称
		int	 icon;			//图标
	}monster[10] = {
		{"独孤六衽", "duguliuren", young_monk,},
		{"公输索", "gongshusuo", young_monk,},
		{"南郭离",	"nanguoli", young_monk,},
		{"公孙咎丘", "gongsunjiuqiu", young_monk,},
		{"王孙须燮",	"wangsunxuxie", young_monk,},
		{"南宫班",	"nangongban", young_monk,},
		{"公羊度", "gongyangdu", young_monk,},
		{"西门松",	"ximensong", young_monk,},
		{"东园望", "dongyuanwang", young_monk,},
		{"北邙歧", "beimangqi", young_monk,},
	};
	
	LONG monster_id;
	
	CContainer * corps_id = load_room(querystr("corps_id"));
	
	if(me->query("corps/quest_time") !=corps_id->query("day"))	
	{
		me->del("corps/quest_count");
		me->del("corps/quest_exp");
		me->delete_temp("corps/quest/count");
		me->set("corps/quest_time",corps_id->query("day"));
	}
	else if(me->query("corps/quest_count") >= 20)
		return notify_fail(snprintf(msg, 255,"%s笑道：今天已经让您够辛苦的了，还是快些去休息休息吧！",name()));
	
	if (me->query("combat_exp") < 10000 )
		return notify_fail(snprintf(msg, 255,"%s道：以你的能力，似乎完成这个任务有些艰难。",name()));
	
	if (me->query_temp("corps/quest/finish"))
		return notify_fail(snprintf(msg, 255,"%s道：哦，你已经完成了任务，为何不来向我说呢？",name()));
	
	if ( (monster_id = me->query_temp("corps/quest/doing")) )
	{
		//判断任务是否失败
		CChar * mon = find_npc(monster_id);
		if(! mon)
			return notify_fail(snprintf(msg, 255,"%s笑嘻嘻的道：好象你的事情还没有办利索吧！",name()));
		
		const char * area = position_npc(mon);
		if(! area) 
			return notify_fail(snprintf(msg, 255,"%s笑嘻嘻的道：好象你的事情还没有办利索吧！",name()));
		
		int diff = me->query_temp("corps/quest/diff");
		tell_object(me, snprintf(msg, 255, "$HIW%s道：宫主有令，%s对本宫意图不利，特命你将其除去，以树我宫威望！",name(), monster[diff].name));
		return 1;
	}
	else if(me->query("corps/quest/renwu"))	//任务丢失
	{
		return notify_fail(snprintf(msg, 255,"%s笑嘻嘻的道：好象你的事情还没有办利索吧！",name()));
	}
	
	if (me->is_busy())
		return notify_fail("你现在很忙。。。");
	
	//随机取一个NPC的场景	
	CNpc * npc = random_npc();
	
	snprintf(msg, 255,"%s道：等我再想想，别急。",name());
	if(! npc) return notify_fail(msg);
	if(npc == this) return notify_fail(msg);	//自己竟然就是妖怪。呵呵。
	if(! living(npc)) return notify_fail(msg);	//这个NPC快不行了。
	if(DIFFERSTR(npc->querystr("race"), "人类") ) return notify_fail(msg);	//非人类NPC
	if(npc->query("no_kill")) return notify_fail(msg);	//是一般玩家不可能找到的随机怪物
	if(npc->query("mfnpc_lvl")) return notify_fail(msg);	//是梦泽山的随机怪物
	
	CContainer * env = npc->environment();
	
	//现在判断NPC大致的方位
	const char * area = position_npc(npc);
	if(! area ) return notify_fail(msg);	//这个NPC没有环境
	if(! area[0]) return notify_fail(msg);	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "fight") ) return notify_fail(msg);	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "野外") ) return notify_fail(msg);	//这个NPC在野外。
	if(env->query("renwu") ) return notify_fail(msg);	//这个NPC在特殊任务的房间中。
	
	int diff = random(10);
	npc = load_npc("pub_mafu");
	npc->set_name(snprintf(msg, 255, "%s%s",monster[diff].name,me->id(1)),monster[diff].id);
	npc->set("icon", monster[diff].icon);
	npc->set("long","");
	npc->set("no_kill",1);
	npc->set("owner",me->id(1));
	npc->set("corps_id",1);
	npc->set("base_name",snprintf(msg, 255, "%s-%s",monster[diff].name,me->id(1)));
	
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
	
	me->set_temp("corps/quest/doing", npc->object_id());
	me->set_temp("corps/quest/diff", diff);			//难度系数
	me->set_temp("corps/quest/name", npc->querystr("name"));	
	
	me->set("corps/quest/renwu", 1);	//接过任务了。
	me->add("corps/quest_count", 1);	//任务总数
	me->add("corps/quest_day", query("tm_day"));
	
	tell_object(me,snprintf(msg, 255, "$HIW%s对%s说道：宫主有令，%s对本宫意图不利，特命你将其除去，以树我宫威望！。如果不出意外，他应该在%s地带。", name(),me->name(), monster[diff].name,env->querystr("area")));
	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s接杀%s的%s的任务。", me->name(1), env->querystr("base_name"), npc->name(1)));
	
	return 1;

}

int do_f(CChar * me)
{
	char msg[255];
	if(! me->query("corps/quest/renwu"))
		return notify_fail(snprintf(msg, 255,"%s微微一皱眉头，道：你来领取过任务吗？怎么我没印象呢？",name()));
	
	if (me->query_temp("corps/quest/finish"))
		return notify_fail(snprintf(msg, 255,"%s道：哦，你已经完成了任务，为何不来向我说呢？",name()));
	
	message_vision(snprintf(msg, 255,"$HIY%s顿时拉下了笑脸，大叹道：“哎，$N怎么连这点小事也办不好呢？”", name()),me);
	
	me->receive_wound("hp", me->query("max_hp") / 3, this);
	me->receive_damage("hp", me->query("max_hp") / 2, this);

	me->SendState(me);
	
	me->delete_temp("corps/quest");
	if(me->query_temp("corps/quest/count")>10)
		me->add_temp("corps/quest/count",-10);
	else
		me->delete_temp("corps/quest/count");
	me->del("corps/quest/renwu");
	return 1;
}

//完成任务汇报
int do_r(CChar * me)
{
	char msg[255];
	if(! me->query("corps/quest/renwu"))
		return notify_fail(snprintf(msg, 255,"%s微微一皱眉头，道：你来领取过任务吗？怎么我没印象呢？",name()));

	if (!me->query_temp("corps/quest/finish"))
		return notify_fail(snprintf(msg, 255,"%s笑嘻嘻的道：好象你的事情还没有办利索吧！",name()));
		
	message_vision(snprintf(msg, 255,"$HIG%s嫣然一笑，道：$N，辛苦你了！",name()),me);
	
	reward_exp(me);
	
	me->delete_temp("corps/quest/finish");
	me->delete_temp("corps/quest/diff");
	me->delete_temp("corps/quest/name");
	me->delete_temp("corps/quest/doing");
	me->del("corps/quest/renwu");
	me->start_busy(6);
	return 1;
}

//给经验
void reward_exp(CChar * me)
{
	char msg[255], tmp[40];
	LONG exp = me->query("level");		

	exp = exp * 2;
	
	exp = exp + random(me->query("level"));	//难度系数

	exp = (random(exp) + exp) / 2;
	exp=exp*(1+me->query_temp("corps/quest/count"));
	if(exp>2000)
		exp=random(500)+1500;
	me->add_temp("corps/quest/count",1);

	me->add("combat_exp", exp);
	me->add("corps/quest_exp",exp);
	int repute=int((random(31)+100)*(10+me->query_temp("corps/quest/count"))/10);
	int contribute=(me->query_temp("corps/quest/count")+1)*(10+random(me->query("dex")))+me->query("level");

	if(me->query("repute")<0)
		repute=-repute;
	me->add("repute",repute);
	me->add("corps/contribute",contribute);
	tell_object(me, snprintf(msg, 255, "$HIC你获得了%s点经验、%d点江湖声望，同时获得了%d点的帮派贡献度。", chinese_number(exp, tmp),repute,contribute));

	me->add("corps/quest_exp",exp);
	me->FlushMyInfo();
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("pq"))
	{
		if(me->query("leave_time"))
		{
			me->add("leave_time",-1);
			me->call_out(do_die1, 3600);
		}
		else
			me->call_out(do_die1, 60);
	}
}

static void do_die1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	if(me->query("leave_time") <= 0)
	{
		char msg[255];
		tell_room(me->environment(), snprintf(msg, 255, "$HIR%s飘然而去。",me->name()));
		destruct(me);
		return;
	}
	me->add("leave_time", -1);
	me->call_out(do_die1, 3600);
}

NPC_END;



