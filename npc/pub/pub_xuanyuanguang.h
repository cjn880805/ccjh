//pub_xuanyuanguang 轩辕光
//秦波 2002、3、21

NPC_BEGIN(CNpub_xuanyuanguang);

virtual void create()
{
	set_name("轩辕光","xuanyuan　guang");
	set("title", "恶赌鬼 ");
	set("foolid",151);        
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",young_woman8);
	
	set("mp", 1400);
	set("max_mp", 1400);
	set("mp_factor", 30);
	set("max_mp", 1000);
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("chat_chance", 5);
	set_skill("unarmed", 90);
	set_skill("sword", 90);
	set_skill("force", 90);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("hengshan_jian", 90);
	set_skill("lingxu_bu", 90);
	
	map_skill("sword", "hengshan_jian");
	map_skill("parry", "hengshan_jian");
	map_skill("dodge", "lingxu_bu");
	
	carry_object("changjian")->wield();
	carry_object("cheng_cloth")->wear();
	//set("task",1);
	set("no_talk",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task"))
	{
		int num,num1;
		int key;
		char msg[255];
		static char bocai[125][20]=
		{
			"yuchi","yuchi","yeerba","yadan","xiaren2","suanmei","soup2","soup","shrimp","sherou","shanhu_baicai","rice","nang",
				"mian","marz","liuli_qiezi","kaoyangtui","kaoya","jiaxin_biji","gourou","egg","chicken","caomei","bocai_fentiao",
				"birddie","basi_shanyao","baozi","zongzi","backleg","yezi","yangxin","yangrou","yangjing","xueli","xiang",
				"turou","tofu","tanghulu","suya","suji","rice3","qingshui_hulu","qingke_m","qingcha","puercha","pork","peanut",
				"paomo","mizhitianou","mitao","mala_doufu","jiudai","jitui","gouroutang","furong_huagu","fotiaoqiang","fish",
				"baozi2","zhutou","yaofen","tianqi","shanshen","mixian","mangguo","huotui2","huotui","hulu2","hu","hdjiudai",
				"hamigua","gao","fuling","duanchang","bicanfeng","yuchandan","yaopin_1","xxqingxin_san","xuelian","shedangao",
				"putizi","menghan_yao","luobo","kongquedan","jingxin_san","hedinghong","geng","gaoyao","gao4","gao3","xuelian2",
				"yaopin_2","xiaohuan_dan","tianxiang_gao","shouwu","shedan","nverhong","jiu","fengmi","fen","yaopin_3",
				"sanxiaosan","jiuping2","jiuping","jiuhua","jinchuang_yao","jinchuang","honey_san","heiyugao","guiyuan","feicui",
				"baiyunwan","zhujingchan","zhuguo","zaisheng","wuchangdan","dahuan_dan","renshen","guiling","baixiang",
				"renshenguo","x_drug","labazhou","baixiang","wuchangdan","renshen",
		};
		if(me->query("age")<16)
			return notify_fail("赌博这门学问，需要等你长大后才能来参悟！");
		if(!strlen(ask))
		{
			AddMenuItem("玩21点", "y", me);
		}
		else if(!strcmp(ask,"y"))
		{
			say("博彩规则\n一、愿赌服输；\n二、每注1000；\n三、游戏中的点数大者为胜；\n四、点数相同时庄家胜；\n五、有一定几率可以获得额外奖励，但不保证可以肯定获得。",me);
			AddMenuItem("我知道了，开始吧！","start",me);
			AddMenuItem("这个规矩我不喜欢","over",me);
		}
		else if(!strcmp(ask,"start"))
		{
			num=me_play(me);
			if(!num)
			{
				num1=npc_play(me);
				if(!num1)
				{
					AddMenuItem("看自己的点数","view",me);
					AddMenuItem("加一张牌","add",me);
					AddMenuItem("开牌","end1",me);
				}
			}
		}
		else if(!strcmp(ask,"add"))
		{
			num=me_play(me);
			if(!num)
			{
				if(me->query_temp("21/npc_count")<15)
					num1=npc_play(me);
				else if(me->query_temp("21/npc_count")<17 && me->query_temp("21/npc_count")<me->query_temp("21/me_count"))
				{
					tell_object(me,"轩辕光看看了自己的底牌，犹豫了一下，一狠心从口袋中掏出1000块排到了赌桌上，又要了一张牌。");
					me->add_temp("21/npc_idx",1);
					if(random(3))
					{
						key=20-me->query_temp("21/npc_count");
						if(key>10)key=10;
						me->add_temp("21/npc_count",key);
					}
					else
					{
						key=random(20-me->query_temp("21/npc_count"))+1;
						if(key>10)key=10;
						me->add_temp("21/npc_count",key);
					}
					num1=0;
					tell_object(me,snprintf(msg, 255, "轩辕光屏住呼吸，轻轻的掀起这张牌，仔细一看，顿时长长的松了一口气，乐滋滋的将牌翻了出来。\n你凑上去一看,发现这张是个$HIR%d$COM！", key));
					tell_object(me,snprintf(msg, 255, "你瞟了一眼轩辕光那边，发现他的桌面上大约已经押上了$HIR%d$COM块金币。\n",me->query_temp("21/npc_idx")*1000));
				}
				else
				{
					tell_object(me,"轩辕光看看了自己的底牌，想了想，摇了摇头，不再接着要牌了。");
					num1=0;
				}
				if(!num1)
				{
					AddMenuItem("看自己的点数","view",me);
					AddMenuItem("加一张牌","add",me);
					AddMenuItem("开牌","end1",me);
				}
			}
		}
		else if(!strcmp(ask,"view"))
		{
			if(me->query_temp("21/me_JQK"))
				tell_object(me,snprintf(msg,255,"你现在的点数是$HIR %d 点半$COM。\n",me->query_temp("21/me_count")));
			else
				tell_object(me, snprintf(msg,255,"你现在的点数是$HIR %d $COM点。\n",me->query_temp("21/me_count")));
			AddMenuItem("看自己的点数","view",me);
			AddMenuItem("加一张牌","add",me);
			AddMenuItem("开牌","end1",me);
		}
		else if(!strcmp(ask,"end1"))
		{
			if(me->query_temp("21/me_count")>me->query_temp("21/npc_count") &&me->query_temp("21/npc_count")<17 )
			{
				tell_object(me,"$HIR你刚想开牌，轩辕光看看了自己的底牌，大叫一声：“小子别动，我还要牌！”吓的你不敢在吱声了。");
				me->add_temp("21/npc_idx",1);
				if(random(3))
				{
					key=20-me->query_temp("21/npc_count");
					if(key>10)key=10;
					key=random(key)+1;
					me->add_temp("21/npc_count",key);
				}
				else
				{
					key=random(20-me->query_temp("21/npc_count"))+1;
					if(key>10)key=10;
					key=random(key)+1;
					me->add_temp("21/npc_count",key);
				}
				tell_object(me,snprintf(msg, 255, "轩辕光扔了1000块金币到了桌上，右手又摸起一张牌，看都不看的直接翻了出来。\n你凑上去一看,发现这张是个$HIR%d$COM！", key));
				tell_object(me,snprintf(msg, 255, "你瞟了一眼轩辕光那边，发现他的桌面上大约已经押上了$HIR%d$COM块金币。\n",me->query_temp("21/npc_idx")*1000));
				AddMenuItem("看自己的点数","view",me);
				AddMenuItem("加一张牌","add",me);
				AddMenuItem("开牌","end1",me);
			}
			else
			{
				if(me->query_temp("21/me_JQK"))
					tell_object(me,snprintf(msg,255,"你现在的点数是 %d 点半",me->query_temp("21/me_count")));
				else
					tell_object(me, snprintf(msg,255,"你现在的点数是 %d 。",me->query_temp("21/me_count")));
				if(me->query_temp("21/npc_JQK"))
					tell_object(me, snprintf(msg,255,"轩辕光现在的点数是 %d 点半",me->query_temp("21/npc_count")));
				else
					tell_object(me, snprintf(msg,255,"轩辕光现在的点数是 %d 。",me->query_temp("21/npc_count")));
				if(me->query_temp("21/me_count")>me->query_temp("21/npc_count"))
				{
					tell_object(me,"$HIC轩辕光恶狠狠的说：小子，算你有种，这些钱你拿去吧！");	
					CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
					tell_object(me, snprintf(msg,255,"$HIR你笑嘻嘻的将赌桌上一堆金币划拉了过来，粗粗一数，大约赚了%d块的一笔小财。",me->query_temp("21/npc_idx")*1000));
					if(me->query_temp("21/me_count")==21)
					{
						me->add_temp("21/me_21",1);
						if(me->query_temp("21/m_21")>=120)me->set_temp("21/m_21",120);
						CContainer * ob = load_item(bocai[random(me->query_temp("21/me_21"))]);
						tell_object(me, snprintf(msg,255,"$HIR看到你翻出的牌是21点，轩辕光哭丧着脸从桌底下不得不摸出了一个%s递给了你。",ob->name(1)));
						ob->move(me);
					}
				}
				else if(me->query_temp("21/me_count")==me->query_temp("21/npc_count"))
				{
					if(me->query_temp("21/me_JQK")>me->query_temp("21/npc_JQK"))
					{
						tell_object(me,"$HIC轩辕光揉了揉眼睛，不相信的看着你说：小子，你真的只比我大半点？");	
						CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
						tell_object(me, snprintf(msg,255,"$HIR你喜滋滋的一手拿着大轩辕光半点的那张牌，另一只手顺手将赌桌上一堆金币划拉了过来，粗粗一数，大约赚了%d块的一笔小财。",me->query_temp("21/npc_idx")*1000));
					}
					else if(me->query_temp("21/me_JQK")==me->query_temp("21/npc_JQK"))
					{
						tell_object(me,"$HIC轩辕光哈哈笑道说：小子，你真的很霉，牌面大小一样，我是庄家照样吃你！");
						tell_object(me, "你哭丧着脸，看着$HIC轩辕光$COM乐呵呵的将面前的一堆金币划拉到他的口袋。");
						tell_object(me, snprintf(msg,255,"$HIR你不甘心的翻了翻自己的钱袋，发现这一次大约输了%d块。",me->query_temp("21/me_idx")*1000));
					}
					else
					{
						tell_object(me, "$HIC你哭丧着脸，看着轩辕光乐呵呵的将面前的一堆金币划拉到他的口袋。");
						tell_object(me, snprintf(msg,255,"$HIC你不甘心的翻了翻自己的钱袋，发现这一次大约输了%d块。",me->query_temp("21/me_idx")*1000));
					}
				}
				else
				{
					tell_object(me, "$HIC你哭丧着脸，看着轩辕光乐呵呵的将面前的一堆金币划拉到他的口袋。");
					tell_object(me, snprintf(msg,255,"$HIC你不甘心的翻了翻自己的钱袋，发现这一次大约输了%d块。",me->query_temp("21/me_idx")*1000));
				}
				me->delete_temp("21/me_count");//总点数
				me->delete_temp("21/me_idx");
				me->delete_temp("21/npc_count");//总张数
				me->delete_temp("21/npc_idx");
				me->delete_temp("21/me_JQK");//半点
				me->delete_temp("21/npc_JQK");
				me->delete_temp("21/me_pai");//牌
				me->delete_temp("21/npc_pai");
				me->add("repute",-10);
				return 1;
			}
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("我怎么是你的对手呢？",me);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

int me_play(CChar * me)
{
	char msg[255];
	if(!CMoney::Player_Pay(me, 1000))
	{
		say("身上都没有钱，拿什么和我来玩呀？一边凉快去！",me);
		return 1;
	}
	int nCount=random(11)+1;
	if(nCount > 10 )
	{
		if(!me->query_temp("21/me_JQK"))
			me->set_temp("21/me_JQK",1);
		else
		{
			me->delete_temp("21/me_JQK");
			me->add_temp("21/me_count",1);
		}
		switch(random(3))
		{
		case 1:
			me->set_temp("21/me_pai","天");
			break;
		case 2:
			me->set_temp("21/me_pai","地");
			break;
		case 3:
			me->set_temp("21/me_pai","人");
			break;
		}
	}
	else
	{
		me->add_temp("21/me_count",nCount);
		snprintf(msg, 255, "%d", nCount);
		me->set_temp("21/me_pai",msg);
	}
	me->add_temp("21/me_idx",1);
	tell_object(me,"$HIR你很爽快的从口袋中掏出1000块，扔到了赌桌上，顺手摸起了一张牌。$COM");
	tell_object(me, snprintf(msg, 255, "你慢慢的掀起牌来，发现这是一张$HIR %s $COM。", me->querystr_temp("21/me_pai")));
	tell_object(me,snprintf(msg, 255, "你已经总共押上了$HIR%d$COM块金币。\n",me->query_temp("21/me_idx")*1000));
	if(me->query_temp("21/me_count")>21)
	{
		if(me->query_temp("21/me_JQK"))
			tell_object(me,snprintf(msg,255,"很不幸,你现在的点数是$HIR %d 点半$COM,超过了21点已经爆了，下次重新再来吧！",me->query_temp("21/me_count")));
		else
			tell_object(me, snprintf(msg,255,"很不幸,你现在的点数是$HIR %d $COM点,超过了21点已经爆了，下次重新再来吧！",me->query_temp("21/me_count")));
		tell_object(me,"$HIC你哭丧着脸，看着轩辕光乐呵呵的将面前的一堆金币划拉到他的口袋。");
		tell_object(me, snprintf(msg,255,"$HIC你不甘心的翻了翻自己的钱袋，发现这一次大约输了%d块。",me->query_temp("21/me_idx")*1000));
		me->delete_temp("21/me_count");//总点数
		me->delete_temp("21/me_idx");
		me->delete_temp("21/npc_count");//总张数
		me->delete_temp("21/npc_idx");
		me->delete_temp("21/me_JQK");//半点
		me->delete_temp("21/npc_JQK");
		me->delete_temp("21/me_pai");//牌
		me->delete_temp("21/npc_pai");
		me->add("repute",-10);
		SendMenu(me);
		return 1;
	}
	SendMenu(me);
	return 0;
}

int npc_play(CChar * me)
{
	char msg[255];
	int nCount=random(11)+1;
	if(nCount > 10 )
	{
		if(!me->query_temp("21/npc_JQK"))
			me->set_temp("21/npcme_JQK",1);
		else
		{
			me->delete_temp("21/npc_JQK");
			me->add_temp("21/npc_count",1);
		}
		switch(random(3))
		{
		case 1:
			me->set_temp("21/npc_pai","天");
			break;
		case 2:
			me->set_temp("21/npc_pai","地");
			break;
		case 3:
			me->set_temp("21/npc_pai","人");
			break;
		}
	}
	else
	{
		me->add_temp("21/npc_count",nCount);
		snprintf(msg, 255, "%d", nCount);
		me->set_temp("21/npc_pai",msg);
	}
	me->add_temp("21/npc_idx",1);
	tell_object(me,"$HIR轩辕光很爽快的从口袋中掏出1000块，扔到了赌桌上，顺手摸起了一张牌。$COM");
	if(me->query_temp("21/npc_count")==nCount ||(!me->query_temp("21/npc_count") && me->query_temp("21/npc_JQK")))
		tell_object(me, "轩辕光慢慢的掀起了底牌，立即又放了下来");
	else
		tell_object(me, snprintf(msg, 255, "轩辕光很轻松的将牌摔了出来，你凑上去一看,发现这张是个$HIR%s$COM！", me->querystr_temp("21/npc_pai")));
	tell_object(me,snprintf(msg, 255, "你瞟了一眼轩辕光那边，发现他的桌面上大约已经押上了$HIR%d$COM块金币。\n",me->query_temp("21/npc_idx")*1000));
	if(me->query_temp("21/npc_count")>21)
	{
		if(me->query_temp("21/npc_JQK"))
			tell_object(me, snprintf(msg,255,"你哈哈一声大笑，道：“倒霉蛋，你的牌现在的点数是$HIR%d点半$COM,已经爆了哟！",me->query_temp("21/npc_count")));
		else
			tell_object(me, snprintf(msg,255,"你哈哈一声大笑，道：“倒霉蛋，你的牌现在的点数是$HIR%d$COM点,已经爆了哟！",me->query_temp("21/npc_count")));
		tell_object(me,snprintf(msg,255,"$HIR你笑嘻嘻的将赌桌上一堆金币划拉了过来，粗粗一数，大约赚了%d块的一笔小财。",me->query_temp("21/npc_idx")*1000));
		CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
		me->delete_temp("21/me_count");//总点数
		me->delete_temp("21/me_idx");
		me->delete_temp("21/npc_count");//总张数
		me->delete_temp("21/npc_idx");
		me->delete_temp("21/me_JQK");//半点
		me->delete_temp("21/npc_JQK");
		me->delete_temp("21/me_pai");//牌
		me->delete_temp("21/npc_pai");
		me->add("repute",-10);
		return 1;
	}
	return 0;
}

NPC_END;




