CNpc * random_npc();

NPC_BEGIN(CNcorps_qingxia);

void create()
{
	set_name("清霞","qing xia");
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
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar *me, char * ask)
{
	if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
	{
		return CNpc::do_talk(me, ask);
	}

	if(me->querymap("corps") && ! me->is_fighting() && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		char msg[255];
		AddMenuItem(snprintf(msg, 255,"向%s领取商人任务",name()), "$0get_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"向%s询问任务",name()), "$0ask_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"向%s要求清除任务",name()), "$0cancel_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"向%s领取「仗剑江湖」任务",name()), "$0get_huan $1", me);
		if(me->querymap("tradepro"))
		{
			AddMenuItem("查询目前的「仗剑江湖」任务说明", "$0show_huan $1", me);
			if(query("取消"))
				AddMenuItem("请求「仗剑江湖」任务失败", "$0cancel_huan $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->querymap("corps") && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		if(strcmp(comm, "ask_renwu") == 0)
			return do_aq(me);
		if(strcmp(comm, "get_renwu") == 0)
			return do_gq(me);
		if(strcmp(comm, "cancel_renwu") == 0)
			return do_cancel(me);
		if(strcmp(comm, "get_huan") == 0 )
			return do_huan(me);
		if(strcmp(comm, "show_huan") == 0 && me->querymap("tradepro") )
			return do_show(me);
		if(strcmp(comm, "cancel_huan") == 0 && me->querymap("tradepro") )
			return do_cancel_huan(me);
		
	}
	return CNpc::handle_action(comm, me, arg);
}

virtual void init(CChar * me)
{	
	CNpc::init(me);

	if( ! is_fighting() ) 
	{
		if(query(me->id(1)) ==1 )
			set(me->id(1),99);
	}
}

//商人任务
int do_aq(CChar * me)
{
	if(!me->query_temp("corps/money/overtime"))
	{
	    message_vision("$n看着$N扬了扬眉毛，微微一笑。", me,this);
		say("你可以从我这里领取任务，以获得经验的奖励。", me);
		say("完成的任务越多，经验就越高。", me);
		say("当然，如果要了任务而没完成，是要受惩罚的。", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	char msg[255];

	i=current_time;
	e=me->query_temp("corps/money/overtime");
	if (i>e)
	{
	    message_vision("$N皱了皱眉头。",this);
		say("对不起……时间已经过了，你没有完成任务。", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say(snprintf(msg, 255,"%s微微蹩眉，道：让我想想……",name()),me);
	say(snprintf(msg, 255, "%s说道：啊，你现在的任务是寻找%s。", name(),me->querystr_temp("corps/money/name")), me);
	say(snprintf(msg, 255, "%s说道：距离任务时限还有%d分%d秒……", name(),e,i), me);
	SendMenu(me);
	return 1;
}

int do_show(CChar * me)
{
	char msg[255];
	if(!me->query_temp("tradepro/money"))
	{
		say("你给我2001文钱，我就帮你查查你现在的任务是什么。", me);
		SendMenu(me);
		return 1;
	}
	me->delete_temp("tradepro/money");
	
	if(current_time > me->query("tradepro/quest_time"))
	{
		say("你来的太迟了，你的任务已经过期了。",me);
		SendMenu(me);
		me->del("tradepro");
		return 1;
	}
	switch(me->query("tradepro/index"))
	{
	case 1:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 去买 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 2:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 去找 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 3:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 杀掉 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 4:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 抓获 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 5:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 在 %s 地带巡逻，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 6:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 前往 %s 讨回公道（杀死掌门大弟子），剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 7:
		snprintf(msg, 255,"你现在的任务（第%d个）是：找到本宫成员%s(%s)，让他到我这里来一下，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_killnpc_name"),
			me->querystr("tradepro/quest_killnpc_id"),me->query("tradepro/quest_time")-current_time);
		break;
	case 8:
		if(me->query("tradepro/quest_pro_index")==1)
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：为了有能力帮助 %s 而承诺提高自身的总经验到 %d，剩余时间是： %d 秒。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：为了有能力帮助 %s 而承诺提高自身的声望到 %d，剩余时间是： %d 秒。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		break;
	case 9:
		snprintf(msg, 255,"你现在的任务（第%d个）是：答应 %s 去保一次镖，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_time")-current_time);
		break;
	case 10:
		if(me->query("tradepro/quest_killnpc_time")-current_time>0)
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 保护 %s ，确保他在剩余时间的 %d 秒中不死。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_killnpc_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 保护 %s ，现在你已经完成了任务。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"));
		}
		break;
	case 11:
		snprintf(msg, 255,"你现在的任务（第%d个）是：给 %s 上贡 %d 两银子，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 12:
		snprintf(msg, 255,"你现在的任务（第%d个）是：给 %s 送去 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 13:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 收集 %s %d份，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 14:
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 获得 %s 的画像，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	}
	say(msg, me);
	SendMenu(me);
	return 1;
}

int do_cancel_huan(CChar * me)
{
	if(!me->querymap("tradepro"))
	{
		say("你并没有领取任务……", me);
		SendMenu(me);
		return 1;
	}
	say("我对你真的是太失望了。。",me);
	SendMenu(me);
	me->del("tradepro");
	return 1;
}

int do_cancel(CChar * me)
{
	if(!me->query_temp("corps/money/overtime"))
	{
		say("你并没有领取任务……", me);
		SendMenu(me);
		return 1;
	}
	say("你给我1001文钱，我就清除这次的任务。", me);
	SendMenu(me);
	return 1;
}

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_huan(CChar * me)
{
	if(me->query("trade/score")< 50000)
		return notify_fail("很抱歉，这个任务只能由萧大人亲自授予的「红顶商人」才可以去做。");

	if(me->query("level")<60)
		return notify_fail("为了你的安全，还是请你继续加强修为到60级后再来找我吧！");
	
	if(me->query("balance") < 100000)
		return notify_fail("请在你的帐号里存足十万！");

	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	if(env->query(snprintf(msg, 255,"repute/%s",me->id(1)))<10000)
		return notify_fail("自入本宫以来，你的表现还是不尽如意，请你多费心提高本宫的声望后再来吧！");

	if(env->query(snprintf(msg, 255,"money/%s",me->id(1)))<10000)
		return notify_fail("自入本宫以来，你的表现还是不尽如意，请你多费心提高本宫的财富后再来吧！。");

	if(me->querymap("tradepro") )
		return notify_fail("你不是已经接过任务了吗？");

	static char index2[5][255] =
	{
		"好久不见$HIW%s$COM了，麻烦你去找到他说我想念他。",
			"$HIW%s$COM前段时间来上门来拜访，我一直都没时间回访,烦请你替我去看看他。",
			"$HIW%s$COM已经失踪很久了,你是否有空替我去找下他，看看最近他怎么样了？",
			"我很想念$HIW%s$COM，你能不能替我送个口信给他，并替我问候他。",
			"前段时间我答应$HIW%s$COM去游山玩水的，但一直忙，请你跟他说声我最近有空，可以一起结伴而行。",
	};

	me->add("balance",-100000);

	CNpc * npc;

	int i;
	const char * area;
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//这个NPC快不行了。
		if(DIFFERSTR(npc->querystr("race"), "人类") ) continue;	//非人类NPC
		if(npc->query("no_kill")) continue;	//是一般玩家不可能找到的随机怪物
		if(npc->query("mfnpc_lvl")) continue;	//是梦泽山的随机怪物
		if(npc->query("no_talk")) continue;	//这个NPC有特殊设置
		
		env = npc->environment();
		
		//现在判断NPC大致的方位
		area = position_npc(npc);
		if(! area ) continue;	//这个NPC没有环境
		if(! area[0]) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "野外") ) continue;	//这个NPC在野外。
		if(env->query("renwu") ) continue;	//这个NPC在特殊任务的房间中。
		break;
	}

	double value = 1800;		//30分钟
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t+i);

	me->set("tradepro/index",2);
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->querymap("corps") && EQUALSTR(who->querystr("corps/id"),querystr("corps_id")))
	{
		long i,money;
		char msg[255];
		
		if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==1001)
		{
			who->delete_temp("corps/money");
			destruct(ob);
			return 1;
		}

		if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==2001 && who->querymap("tradepro") )
		{
			who->set_temp("tradepro/money",1);
			destruct(ob);
			return 1;
		}
		
		if ( DIFFERSTR(ob->querystr("id"), who->querystr_temp("corps/money/id")) || DIFFERSTR(ob->querystr("name"), who->querystr_temp("corps/money/name")) )
		{	
			say(snprintf(msg, 255,"%s扬扬眉毛，说：这是什么东西？", name()),who);
			SendMenu(who);
			return 0;
		}
		
		if( ob->query("is_user") )
		{
			say(snprintf(msg, 255,"%s摇摇头：这是什么东西，我不要！", name()), who);
			SendMenu(who);
			return 0;
		}
		
		long e;
		
		e=who->query_temp("corps/money/overtime");
		i=current_time;
		
		if (i>e)
		{
			destruct(ob);	
			say(snprintf(msg, 255,"%s一扬眉毛，说：你知道时间已经过了吗？", name()), who);
			SendMenu(who);
			return 1;
		}
		
		who->add_temp("corps/money/finish",1);
		i=who->query_temp("corps/money/exp");
		e=who->query_temp("corps/money/finish");
		money=e;
		if(money>150)
			money=100+random(50);
		if(e<30)
			i=i*(e+5)/5;
		else
			i=i*6;
		i=(random(i)+i)*6/3;
		i=i+(100-who->query("level"))/3;
		
		who->add("combat_exp",i);
		int repute=1;
		if(who->query("repute")<0)
			repute=-repute;
		who->add("repute",repute);
		who->delete_temp("corps/money/id");
		who->delete_temp("corps/money/name");
		who->delete_temp("corps/money/exp");
		who->delete_temp("corps/money/overtime");
		
		CContainer * env = load_room(querystr("corps_id"));
		env->add(snprintf(msg, 255,"money/%s",who->id(1)),money);
		env->add("corps/money",money);
		
		message_vision("$n对$N扬了扬眉毛，露出一丝笑容。", who,this);
		tell_object(who,snprintf(msg, 255, "你获得了%d经验、%d点的江湖声望、%d点的帮派财富！", i,repute,money));
		
		destruct(ob);
	}

	return 1;
}

int do_gq(CChar * me)
{
	long i;
	long e;
	char msg[255];
	
	static char weapon_name[62][40] = {
		"blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fenshuici","fork","fuchen","futou",
			"hammer","heilongbian",	"hothammer","huaji","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","leizhendang","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ruanjian",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","tiepipa","tongren","walkingstick","wandao","wodao","xblade",
			"xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijin_staff",
	};
	
	static char cloth_name[139][40]={
		"cloth","pixue","dao_xie","daopaocyan_cloth","female1_cloth","female2_cloth","female3_cloth",
			"female6_cloth","flower_shoe","green_cloth","greenrobe","greyrobe","gunny_shoes","hui_cloth",
			"huwan","huyao","jin","jindai","jinduan","junfu","male1_cloth",
			"male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","male_shoe","necklace",
			"ni_cloth","ni_xie","pink_cloth","piqiu","qing_cloth","qingyi","r_jiasha","ring",
			"seng_cloth","seng_xie","sengmao","sengxie","shepi","shoe","shoutao","shuikao","shouzhuo","tiejia",
			"surcoat","test","toukui","white_robe","wuxingfu","xu_cloth","xuan_cloth","y_jiasha","yaodai",
			"yayi_cloth","ycloth","yupei","zhanyi","zhenzhu","tiezhitao","zichoushan","b_jiasha","baguafu",
			"baichou","baipao","bduanqun","beixin","belt","blackcloth","bluecloth","boots","bu_shoes",
			"bupao","c_jiasha","caoxie","changpao","changpao2","cheng_cloth","choupao","cloth2","connie",
			"cuiyu","cycle","cynrobe","dao_cloth","doupeng","dress","feather","fu_cloth",
			"goldring","goupi","guazi","gui_dress","hat","hupi","hushenfu","jade_belt","jinsijia","jjunfu","kenao","lace",
			"linen","liu_dress","magcloth","magua","marry_dress","mini_dress","moon_dress","pink_dress",
			"qi_dress","qun","red_dress","ruanwei","scarf","sha_dress","shoes","shoupa","skirt",
			"shudai","tduanqun","tiebeixin","tiehuwan","tiehuyao","tieshou","tongqun","ttoujin","wchangqun","wcloth","wdahui",
			"whitecloth","whitecloth1","xian_cloth","xiaoao","xiu_cloth","xiu_scarf","yan_dress","zi_dress","mask",
	};
	
	static char food_name[48][40]={
		"baihe","baozi","duanchang","gourou","guijia","guiyuan","heiyugao","honghua",
			"jinchuang","jitui","jiudai","jindan","kaoya","marz","menghan_yao","mizhitianou","moyao",
			"nverhong","peanut","putizi","qingdan","qingke_m","renshen",
			"shedan","shedangao","sherou","turou","x_drug","xiaohuan_dan","xionghuang",
			"yadan","yangxin","yuchandan","zongzi","zhutou","zhujingchan","yangjing","xiang","gao","egg","dahuan_dan",
			"cha","caomei","cake","luobo","caogeng","jingxin_san","honey",
	};
	
	i=current_time;

	e=me->query_temp("corps/money/overtime");
	if(e && i>e)
	{
	    message_vision("$N扬了扬眉。",this);
		say("你上一个任务没有完成……", me);
		SendMenu(me);
		me->delete_temp("corps/money");	
	
		me->set("hp",me->query("hp")/2);
		me->set("mp",me->query("mp")/2);
	}

	if(e && i<=e)
	{
	    message_vision("$N扬了扬眉。",this);
		say("你上一个任务还没完成……", me);
		SendMenu(me);
		return 1;
	}

	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	const char * shuiname = "";
	const char * shuiid = "";
	int shuitime = 0;
	int shuiexp = 0;

	int task = random(3);

	CContainer * item_name;
	switch(task)
	{
	case 0:
		item_name=load_item(cloth_name[random(139)]);
		break;
	case 1:
		item_name=load_item(food_name[random(48)]);
		break;
	case 2:
		item_name=load_item(weapon_name[random(62)]);
		break;
	}
	
	shuiname=item_name->name();
	shuiid=item_name->id();
	shuitime=60;
	switch(i/10)
	{
	case 0:
		shuiexp=random(3)+2;
		break;
	case 1:
		shuiexp=random(6)+5;
		break;
	case 2:
		shuiexp=random(8)+10;
		break;
	case 3:
		shuiexp=random(11)+20;
		break;
	case 4:
		shuiexp=random(18)+30;
		break;
	case 5:
		shuiexp=random(22)+50;
		break;
	case 6:
		shuiexp=random(30)+50;
		break;
	case 7:
		shuiexp=random(14)+60;
		break;
	case 8:
		shuiexp=random(40)+60;
		break;
	default:
		shuiexp=random(20)+80;
	}
	
	me->set_temp("corps/money/name",shuiname);
	me->set_temp("corps/money/id",shuiid);
	me->set_temp("corps/money/exp",shuiexp);

	say(snprintf(msg, 255, "%s说道：去找%s给我……", name(),shuiname), me);
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("corps/money/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "%s说道：给你%d分%d秒去完成吧。", name(),e,i), me);
	SendMenu(me);

	return 1;
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



