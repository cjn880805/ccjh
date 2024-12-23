//wiz_mingjiaokill.h 明教杀手
//秦波 2002、3、22

NPC_BEGIN(CNwiz_mingjiaokill);

void create()
{
	set_name("明教杀手", "MingJiao ShaShou");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 80);

	set("time",5);
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

//	int day = newtime->tm_mday;
	
	if(newtime->tm_hour >= 1)//每月8、18、28日20点开始启动“围攻光明顶”的任务
//	if((day%10)!=2 && newtime->tm_hour >= 16)//每月8、18、28日20点开始启动“围攻光明顶”的任务

	{
		CContainer * env = me->environment();
		env->set("mj/start",1);
		me->call_out(do_kill, 60);
//		int passtime = newtime->tm_min * 60 + newtime->tm_sec;	//已经过去的秒
//		call_out(do_renew, 3600 - passtime);
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	int i,j,k,count;
	if(me->query("time")<1)
	{
		static char mingjiaodizi[25][20]={"风字门弟子","雷字门弟子","天字门弟子","地字门弟子","青龙坛弟子","白虎坛弟子","玄武坛弟子","朱雀坛弟子","神蛇坛弟子","锐金旗弟子","厚土旗弟子","烈火旗弟子","巨木旗弟子","洪水旗弟子","天微堂弟子","天市堂弟子","五散人亲传弟子","蝠王亲传弟子","鹰王亲传弟子","狮王亲传弟子","龙王亲传弟子","光明左使亲传弟子","光明右使亲传弟子","总教护法使","教主亲传弟子"};
		static int shumu[25]={2,2,2,2,5,5,5,5,5,3,4,3,3,4,1,1,3,2,2,2,2,1,1,1,1};
		static char changjing[67][20]={"明教道家竹舍","明教四门广场","明教雷门宿舍","明教四门广场","明教天门男舍","明教四门广场","明教地门女舍","明教四门广场","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教昆仑山下","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教昆仑山下","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教昆仑山下","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教昆仑山下","明教青石大道3","明教山门","明教青石大道2","明教青石大道1","明教昆仑山下","明教锐金旗大厅","明教青石大道5","明教青石大道4","明教厚土旗大厅","明教青石大道7","明教青石大道8","明教青石大道9","明教烈火旗大厅","明教烈火旗牌坊","明教悬天崖","明教巨木旗大厅","明教青石大道7","明教青石大道8","明教洪水旗大厅","明教青石大道6","明教青石大道5","明教青石大道4","明教天微堂","明教天微堂","明教广场","明教饭堂","明教刑堂","明教广场","明教大殿","明教广场","明教大殿","明教广场","明教大殿","明教广场","明教大殿","明教大殿","明教大殿","明教悬天崖","明教大殿"};
		for(k=0;k<25;k++)
		{
			for(i=0;i<shumu[k];i++)
			{
				count=random(5)+1;
				for(j=0;j<count;j++)
				{
					CNpc * shounpc = load_npc("pub_mafu");
					shounpc->set_name(snprintf(msg, 255, "%s",mingjiaodizi[k]));
					shounpc->set("title", "明教");
					shounpc->create_family("明教", 3, "明教弟子");
					shounpc->set("long","");
					shounpc->move(load_room(snprintf(msg, 255, "%s",changjing[me->query("changjing")])));
				}
				me->add("changjing",1);
			}
		}
		CNpc * shounpc1 = load_npc("mingjiao_chengchaofeng");
		shounpc1->move(load_room("明教昆仑山下"));
		CNpc * shounpc2 = load_npc("mingjiao_baiguishou");
		shounpc2->move(load_room("明教山门"));
		CNpc * shounpc3 = load_npc("mingjiao_changjinpeng");
		shounpc3->move(load_room("明教四门广场"));
		CNpc * shounpc4 = load_npc("mingjiao_fenggongying");
		shounpc4->move(load_room("明教悬天崖"));
		me->call_out(do_start, 1);
	}
	else
	{
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n$HIC%s开始在叫嚣着要围剿$HIY明教光明顶$HIC，倒记时开始，还剩%d分钟。$HIC\n",me->name(1),me->query("time")));
		me->call_out(do_kill, 60);
	}
	me->add("time",-1);
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	
	static char menpai[6][20]={"少林","武当","娥眉","崆峒","华山","昆仑"};
	static char menpai1[6][20]={"shaolin dizi","wudang dizi","emei dizi","kongdong dizi","hashan dizi","kunlun duzi"};
	
	if(me->query("kill/npc")<6)
	{
		switch(me->query("kill/level"))
		{
		case 0:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的各位弟子领命，上山于坎位强攻$HIY魔教总舵光明顶$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 1:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的众位师弟自离位包抄$HIY魔教总舵光明顶后山$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 2:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255,
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师弟师妹增援震位，魔教反扑势大。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 3:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师兄师姐速自巽位奇袭$HIY魔教总舵光明顶$HIC，不得延误。$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 4:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师叔于乾位攻山，务必小心魔教各匪首！\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 5:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的师伯谨守坤位下山要道，勿使败退妖人逃脱！\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 6:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的各位前辈师长请从艮位空处直击$HIY魔教总舵光明顶大殿$HIC。\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 7:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"传六派盟主玄赐大师令：\n$HIC请$HIY第%d轮%s派$HIC的耆宿长老合力扑灭兌位魔教妖火！$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		}
		for(int i=0;i<23-me->query("kill/level")*2;i++)
		{
//			snprintf(msg, 20, "mfnpc_%d", me->query("kill/npc")+1);
//			CNpc * mfnpc = load_npc(msg);
			CNpc * killnpc = load_npc("pub_wudangdizi");
			killnpc->set_name(snprintf(msg, 255, "%s弟子",menpai[me->query("kill/npc")]));
			killnpc->set("id", snprintf(msg, 255, "%s",menpai1[me->query("kill/npc")]));
			killnpc->set("kill/level",me->query("kill/level"));
			killnpc->del("attitude");
//不再杀已经杀死重新刷新出来的NPC
			CContainer * obj =ob->environment();
			static char mjboss[30][20]={"风啸","雷响","天高","地阔","程笑风","高山青","白鹤寿","常金雕","封杯蛇","庄锵","颜坛","辛燃","闻劲草","唐海","殷留侯","李天壁","周疯","张庸","笑不得","彭寒玉","冷逊","韦三笑","殷天罡","谢谦","黛安娜","杨遥","范逍","张无敌","小仪","胡铁牛"	};
			if(obj->query("mj/count"))
			{
				for(int ii=0;ii<30;ii++)
				{
					if(obj->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
					{
						killnpc->add("nokill/count",1);
						killnpc->set(snprintf(msg, 255,"nokill/%d",killnpc->query("nokill/count")),mjboss[ii]);
					}
				}
			}

			killnpc->move(load_room("明教昆仑山下"));
		}
		me->add("kill/npc",1);
		me->call_out(do_start, 20);
	}
	else if(me->query("kill/level")<7)
	{
		me->del("kill/npc");
		me->add("kill/level",1);
		me->call_out(do_start, 180);
	}
}

char * chat_msg()
{
	char msg[255];
	static char menpai1[6][20]={"少林","武当","娥眉","崆峒","华山","昆仑"};
	CContainer * obj = environment();
	if(obj->query("mj/count")==30)
	{ 
		g_Channel.do_channel(&g_Channel, 0, "party", "\n当此之际，明教教众俱知今日大数已尽，众教徒一齐挣扎爬起，除了身受重伤无法动弹者之外，\n各人盘膝而坐，双手十指张开，举在胸前，作火焰飞腾之状，念诵明教的经文：“\n$HIR焚我残躯，熊熊圣火，\n生亦何欢，死亦何苦？\n为善除恶，惟光明故，\n喜乐悲愁，皆归尘土。\n怜我世人，忧患实多！”\n");
		g_Channel.do_channel(&g_Channel, 0, "chat",	"\n少林派玄赐大师大声发令:\n$HIR魔教妖火业已被我六大门派联手熄灭！\n华山派和崆峒派各位，请将场上的魔教余孽一概诛灭。\n武当派从西往东搜索，峨嵋派从东往西搜索，勿使魔教有一人漏网。\n昆仑派预备火种，焚烧魔教巢穴。\n少林子弟各取法器，诵念往生经文，替六派殉难的英雄、魔教教众超度，化除冤孽。\n");
		obj->del("mj");
	}
	if(obj->query("六派/count"))
	{ 
		if(obj->query("六派/count")==768)
		{
			g_Channel.do_channel(&g_Channel, 0, "party", "$HIC\n睿智英明的琐罗亚斯德先知哦，你流传下来的圣火，历经危机终于仍然燃烧在昆仑山顶，神的福祉永远照耀在众弟子心中。\n\n				圣火长明，圣教长存！\n");
			g_Channel.do_channel(&g_Channel, 0, "chat",	"$HIR\n\n明教弟子维护圣火，齐心协力，历经艰险困苦，独拒来犯六大门派，护教成功！\n\n");
			obj->del("六派");
		}
		else
		{
			for(int i=0;i<6;i++)
			{
				if(obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i]))==128)
				{
					obj->set(snprintf(msg, 255, "六派/%s弟子",menpai1[i]),-1);
					g_Channel.do_channel(&g_Channel, 0, "party", 
						snprintf(msg, 255,"$HIR围攻光明顶的%s派门人已经全部击退，圣教圣火，光照千古。\n",menpai1[i]));
				}
				else if(obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i]))>80 && !obj->query(snprintf(msg, 255, "六派/%s标志",menpai1[i])) )
				{
					obj->set(snprintf(msg, 255, "六派/%s标志",menpai1[i]),1);
					g_Channel.do_channel(&g_Channel, 0, "chat", 
						snprintf(msg, 255,"$HIR\n围攻光明顶的%s派弟子损失惨重，已有%d人壮烈捐躯。\n",menpai1[i],obj->query(snprintf(msg, 255, "六派/%s弟子",menpai1[i]))));
				}
			}
		}	
	}
	return "";
}
NPC_END;
