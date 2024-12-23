//wiz_mingjiaokill.h 明教杀手
//秦波 2002、3、22

NPC_BEGIN(CNwiz_mingjiaokill);

void create()
{
	set_name("系统精灵"," ");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 80);
	set("no_kill",1);

	set("time",15);
	set("renwu",1);//任务开关
	call_out(do_renwu, 1);
	create_family("明教", 9, "明教杀手");
};


static void do_renwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 

	int day = newtime->tm_mday;
	
	if((day%10)==8 && newtime->tm_hour >= 20 && me->query("renwu"))//每月8、18、28日18点开始启动“围攻光明顶”的任务
	{
		CNpc * shounpc1 = load_npc("pub_fengshanshi");
		shounpc1->move(load_room("明教昆仑山下"));
		me->call_out(do_kill, 60);
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	int i,j,k,count;
	if(me->query("renwu"))
	{
		if(me->query("time")<1)
		{
			static char mingjiaodizi[25][20]={"风字门弟子","雷字门弟子","天字门弟子","地字门弟子","青龙坛弟子","白虎坛弟子","玄武坛弟子","朱雀坛弟子","神蛇坛弟子","锐金旗弟子","厚土旗弟子","烈火旗弟子","巨木旗弟子","洪水旗弟子","天微堂弟子","天市堂弟子","五散人亲传弟子","蝠王亲传弟子","鹰王亲传弟子","狮王亲传弟子","龙王亲传弟子","光明左使亲传弟子","光明右使亲传弟子","总教护法使","教主亲传弟子"};
			static int shumu[25]={2,2,2,2,5,5,5,5,5,3,4,3,3,4,1,1,3,2,2,2,2,1,1,1,1};
			static char changjing[67][20]={"明教道家竹舍","明教四门广场","明教雷门宿舍","明教四门广场","明教天门男舍","明教四门广场","明教地门女舍","明教四门广场","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教青石大道1","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教青石大道1","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教青石大道1","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教青石大道1","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教青石大道1","明教锐金旗大厅","明教青石大道5","明教青石大道4","明教厚土旗大厅","明教青石大道7","明教青石大道8","明教青石大道9","明教烈火旗大厅","明教烈火旗牌坊","明教悬天崖","明教巨木旗大厅","明教青石大道7","明教青石大道8","明教洪水旗大厅","明教青石大道6","明教青石大道5","明教青石大道4","明教天微堂","明教天微堂","明教广场","明教饭堂","明教刑堂","明教广场","明教大殿","明教广场","明教大殿","明教广场","明教大殿","明教广场","明教大殿","明教大殿","明教大殿","明教悬天崖","明教大殿"};
			for(k=0;k<25;k++)
			{
				for(i=0;i<shumu[k];i++)
				{
					count=random(3)+1;
					for(j=0;j<count;j++)
					{
						CNpc * shounpc = load_npc("pub_mjdizi");
						shounpc->set_name(snprintf(msg, 255, "%s",mingjiaodizi[k]));
						shounpc->set("title", "明教");
						shounpc->create_family("明教", 3, "明教弟子");
						shounpc->set("long","");
						shounpc->set("cailiao",1);
						shounpc->move(load_room(snprintf(msg, 255, "%s",changjing[me->query("changjing")])));
					}
					me->add("changjing",1);
				}
			}
			CNpc * shounpc1 = load_npc("mingjiao_chengchaofeng");
			shounpc1->move(load_room("明教青石大道1"));
			CNpc * shounpc2 = load_npc("mingjiao_baiguishou");
			shounpc2->move(load_room("明教山门"));
			CNpc * shounpc3 = load_npc("mingjiao_changjinpeng");
			shounpc3->move(load_room("明教四门广场"));
			CNpc * shounpc4 = load_npc("mingjiao_fenggongying");
			shounpc4->move(load_room("明教悬天崖"));
			CContainer * env = me->environment();
			env->set("mj/start",1);
			me->call_out(do_start, 1);
		}
		else
		{
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIW六派连枝接同盟，倚天为令号群雄。誓死围歼光明顶，斩妖除魔救苍生。\n$HIC现在离六大门派围攻光明顶还剩%d分钟。$HIC\n",me->query("time")));
			me->call_out(do_kill, 60);
		}
		me->add("time",-1);
	}
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	CNpc * killnpc, * bossnpc;
	if(me->query("renwu"))
	{
		CContainer * env = me->environment();
		static char menpai[6][20]={"少林","武当","娥眉","崆峒","华山","昆仑"};
		static char mjboss[30][20]={"风啸","雷响","天高","地阔","程笑风","高山青","白鹤寿","常金雕","封杯蛇","庄锵","颜坛","辛燃","闻劲草","唐海","殷留侯","李天壁","周疯","张庸","笑不得","彭寒玉","冷逊","韦三笑","殷天罡","谢谦","黛安娜","杨遥","范逍","张无敌","小仪","胡铁牛"	};
		static char menpai1[6][20]={"shaolin dizi","wudang dizi","emei dizi","kongdong dizi","hashan dizi","kunlun duzi"};
		
		if(me->query("kill/npc")<6 && env->query("mj/start"))
		{
			switch(me->query("kill/level"))
			{
			case 0:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的各位弟子领命，上山于艮位强攻$HIY魔教总舵光明顶$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 1:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的众位师弟自坎位包抄$HIY魔教总舵光明顶后山$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 2:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255,
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师弟师妹增援震位，魔教反扑势大。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 3:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师兄师姐速自坤位奇袭$HIY魔教总舵光明顶$HIC，不得延误。$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 4:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师叔于巽位攻山，务必小心魔教各匪首！\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 5:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师伯谨守离位下山要道，勿使败退妖人逃脱！\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 6:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的各位前辈师长请从坎位空处直击$HIY魔教总舵光明顶大殿$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 7:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的耆宿长老合力扑灭震位魔教妖火！$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 8:
				if(!me->query("mj/boss"))
					g_Channel.do_channel(&g_Channel, 0, "chat", "传六派盟主玄赐大师令：\n$HIC请$HIY娥眉派$HIC灭尽师太以“倚天剑”为令，统领六派众弟子自乾位痛击魔教残余妖孽，完成灭魔大业！$HIC\n$COM");
				break;
			}
			for(int i=0;i<27-me->query("kill/level")*2;i++)
			{
				if(me->query("kill/level")<8)
				{
					snprintf(msg, 20, "pub_mjkill%d", me->query("kill/npc")+1);
					killnpc = load_npc(msg);
					killnpc->set_name(snprintf(msg, 255, "%s弟子",menpai[me->query("kill/npc")]));
					killnpc->set("id", snprintf(msg, 255, "%s",menpai1[me->query("kill/npc")]));
					killnpc->set("kill/level",me->query("kill/level")+1);
					killnpc->del("attitude");
					//不再杀已经杀死重新刷新出来的NPC
					if(env->query("mj/count"))
					{
						for(int ii=0;ii<30;ii++)
						{
							if(env->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
							{
								killnpc->add("nokill/count",1);
								killnpc->set(snprintf(msg, 255,"nokill/%d",killnpc->query("nokill/count")),mjboss[ii]);
							}
						}
					}
					killnpc->move(load_room("屠宰场"));
				}
				else if(!me->query("mj/boss"))
				{
					bossnpc = load_npc("pub_mjkillboss");	
					if(env->query("mj/count"))
					{
						for(int ii=0;ii<30;ii++)
						{
							if(env->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
							{
								bossnpc->add("nokill/count",1);
								bossnpc->set(snprintf(msg, 255,"nokill/%d",bossnpc->query("nokill/count")),mjboss[ii]);
							}
						}
					}
					me->set("mj/boss",1);
					bossnpc->move(load_room("明教广场"));
				}
			}
			me->add("kill/npc",1);
			me->call_out(do_start, 30);
		}
		else if(me->query("kill/level")<8)
		{
			me->del("kill/npc");
			me->add("kill/level",1);
			me->call_out(do_start, 120);
		}
	}
}

char * chat_msg()
{
	if(query("go"))
	{
		CNpc * shounpc1 = load_npc("pub_fengshanshi");
		shounpc1->move(load_room("明教昆仑山下"));
		call_out(do_kill, 60);
		del("go");
	}
	char msg[255];
	static char menpai1[6][20]={"少林","武当","娥眉","崆峒","华山","昆仑"};
	CContainer * obj = environment();
	if(obj->query("mj/count")==30 && obj->query("mj/start"))
	{ 
		g_Channel.do_channel(this, NULL, "party", "\n              明教教众俱知今日大数已尽，众教徒一齐挣扎爬起，除了身受重伤无法动弹者之外，各人盘膝而坐，\n              双手十指张开，举在胸前，作火焰飞腾之状，念诵明教的经文：\n$HIR                            焚我残躯，熊熊圣火，\n                            生亦何欢，死亦何苦？\n                            为善除恶，惟光明故，\n                            喜乐悲愁，皆归尘土。\n                            怜我世人，忧患实多！\n");
		g_Channel.do_channel(&g_Channel, 0, "chat",	"少林派玄赐大师大声发令:\n$HIR              善哉！善哉！\n              魔教妖火业已被我六大门派联手熄灭！\n              华山派和崆峒派各位，请将场上的魔教余孽一概诛灭。\n              武当派从西往东搜索，峨嵋派从东往西搜索，勿使魔教有一人漏网。\n              昆仑派预备火种，焚烧魔教巢穴。\n              少林子弟各取法器，诵念往生经文，替六派殉难的英雄、魔教教众超度，化除冤孽。\n");
		
		static char bnline[28][20]={"明教昆仑山下","明教青石大道1","明教四门广场","明教地门女舍","明教天门男舍","明教雷门宿舍","明教道家竹舍","明教青石大道2","明教山门","明教青石大道3","明教悬天崖","明教烈火旗牌坊","明教青石大道7","明教青石大道8","明教青石大道9","明教厚土旗大厅","明教巨木旗大厅","明教青石大道4","明教青石大道5","明教青石大道6","明教洪水旗大厅","明教锐金旗大厅","明教烈火旗大厅","明教天微堂","明教广场","明教饭堂","明教刑堂","明教大殿"};
		for(int i=0;i<28;i++)
		{
			CNpc * clnpc = load_npc("pub_chuanlinshi");
			clnpc->move(load_room(bnline[i]));
		}
		static char city[64][20]={"武陵春正厅","成都中","佛山","佛山北门","佛山东门","佛山西门","佛山南门","襄阳西南","襄阳西北","襄阳东南","襄阳东北",	"扬州东北","扬州东南","扬州西南","扬州西北","长安","华山村","白驼山东街","武当玄岳门","重阳宫大门","古墓墓门","血刀门雪山北麓","星宿海天山山路1","神龙教海滩","少林寺石阶","大理城东","大理城西","泉州","泉州北门","嘉兴城","福州西","苏州中","苏州南","苏州北","燕子坞龙凤厅","桃花岛","北京东北","北京西北","北京西南","北京东南","关外宁远","大理城南诏德化碑","大理城太和城","大理城官道3","大理城官道2","大理城官道1","万劫谷小厅","峨嵋报国寺山门","灵州西","灵州东",	"黑木崖林间小道","衡阳城","台湾澎湖岛","台湾鸡笼港","大理城黑龙岭","大理城树林外","大理城林间小道1","大理城林间小道2","大理城南门","大理城清溪三潭","大理城碧鸡山顶","大理城沿池小路2","大理城滇池沿岸1","大理城罗伽甸"};
		for(int i=0;i<64;i++)
		{
			CNpc * zsnpc = load_npc("pub_zueijiaoshi");
			zsnpc->move(load_room(city[i]));
		}
		obj->del("mj/start");
		obj->set("mj/lost",1);
		call_out(do_end, 180);
	}
	if(obj->query("六派/count") && obj->query("mj/start"))
	{ 
		if(obj->query("六派/count")==961 &&obj->query("六派/boss")==1)
		{
			g_Channel.do_channel(this, NULL, "party", "\n\n              $HIC睿智英明的琐罗亚斯德先知哦，你流传下来的圣火，历经危机终于仍然燃烧在昆仑山顶，神的福祉永远照耀在众弟子心中。\n                                          $HIR圣火长明，圣教长存！\n");
			obj->del("mj/start");
			call_out(do_end, 180);
			call_out(do_end_ok, 3600);
			g_Channel.do_channel(&g_Channel, 0, "chat",	"$HIR\n\n              明教弟子维护圣火，齐心协力，历经艰险困苦，独拒来犯六大门派，护教成功！\n\n");
		}
		else
		{
			for(int i=0;i<6;i++)
			{
				if(obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i]))>=160)
				{
					obj->set(snprintf(msg, 255, "六派/%s弟子",menpai1[i]),-1);
					g_Channel.do_channel(this, NULL, "party",
						snprintf(msg, 255,"$HIR围攻光明顶的%s派门人已经全部击退，圣教圣火，光照千古。\n",menpai1[i]));
				}
				else if(random(obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i])))>80 && !obj->query(snprintf(msg, 255, "六派/%s标志",menpai1[i])) )
				{
					obj->set(snprintf(msg, 255, "六派/%s标志",menpai1[i]),1);
					g_Channel.do_channel(&g_Channel, 0, "chat", 
						snprintf(msg, 255,"$HIR围攻光明顶的%s派弟子损失惨重，已有%d人壮烈捐躯。\n",menpai1[i],obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i]))));
				}
			}
		}	
	}
	return "";
}

static void do_end(CContainer * ob, LONG param1, LONG param2)
{	
	CContainer * env = (CChar *)ob->environment();
	if(!env->query("mj/lost"))
		env->set("mjok",1);
	env->del("mj");
	env->del("六派");
	env = load_room("明教道家竹舍");
	env->set("no_fight",1);
	env = load_room("明教烈火旗牌坊");
	env->set("no_fight",1);
	env = load_room("明教天门男舍");
	env->set("no_fight",1);
	env = load_room("明教地门女舍");
	env->set("no_fight",1);
	env = load_room("明教雷门宿舍");
	env->set("no_fight",1);
}

static void do_end_ok(CContainer * ob, LONG param1, LONG param2)
{	
	CContainer * env = (CChar *)ob->environment();
	env->del("mjok");
	ob->set("time",15);
}
NPC_END;




