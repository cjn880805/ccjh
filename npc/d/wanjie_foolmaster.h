//lanwood 
//	任务：找到坏人杀掉。
//	原创：MM
//	修改：Lanwood
//	日期：2001-04-12
//	增加范围到全世界NPC。只要是NPC，都有可能被通缉。
//	调整任务难度，通缉NPC的强度是玩家的2倍，使用玩家最拿手的技能。
//	会自己使用可用的PERFORM
//	经验是玩家的1。2 ~ 2 倍，技能等级是玩家的1。2 ~ 2倍  
//  1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0  通缉9种不同的怪物

//	使用武器动态生成，带owner属性。damage为玩家的damage。
//	复制玩家的apply里的attack，dodge，defense，armor，parry。
//	奖励：100万以下，奖励经验。exp = (level * 65 ~ level * 130)
//		  100万以上，可学习随机技能。花经验。如果没学成，奖励经验：(level * 60 ~ level * 120) * 难度系数

CNpc * random_npc();

NPC_BEGIN(CNwanjie_foolmaster);

void create()
{
		set_name("劫余老人","jieyugu zhuren");

        set("long", "他是万劫谷的主人，自号劫余老人。\n");
        set("title", "万劫谷主");
        set("gender", "男性");
        set("age", 53);

        set("attitude", "peaceful");
	 	set("icon",old_man1);

        set("per", 1);
        set("str", 500);
        set("hp", 500000);
        set("max_hp", 500000);

        set("combat_exp", 20000000);
        set_skill("unarmed", 800);
		set("no_talk",1);
		set("task_open", 1);	//任务开放
/*
		//填表
		room_decode.set("白驼", "白驼山一带");
		room_decode.set("北京", "北京附近");
		room_decode.set("长安", "长安一带");
		room_decode.set("成都", "成都附近");
		room_decode.set("大理", "大理一带");
		room_decode.set("峨嵋", "峨嵋附近");
		room_decode.set("佛山", "佛山附近");
		room_decode.set("福州", "福州某地");
		room_decode.set("关外", "关外一带");
		room_decode.set("归云", "归云山庄");
		room_decode.set("古墓", "终南一带");
		room_decode.set("杭州", "杭州附近");
		room_decode.set("黑木", "黑木崖附近");
		room_decode.set("衡山", "衡山附近");
		room_decode.set("恒山", "恒山附近");
		room_decode.set("衡阳", "衡阳一带");
		room_decode.set("黄河", "黄河一带");
		room_decode.set("华山", "华山附近");
		room_decode.set("嘉兴", "杭州附近");
		room_decode.set("灵鹫", "天山一带");
		room_decode.set("灵州", "灵州某地");
		room_decode.set("梅庄", "梅庄一带");
		room_decode.set("明教", "昆仑明教");
		room_decode.set("南阳", "扬州附近");
		room_decode.set("青城", "成都附近");
		room_decode.set("泉州", "泉州附近");
		room_decode.set("少林", "嵩山一带");
		room_decode.set("舍身", "武当附近");
		room_decode.set("嵩山", "嵩山一带");
		room_decode.set("苏州", "苏州附近");
		room_decode.set("泰山", "泰山山上");
		room_decode.set("台湾", "台湾一地");
		room_decode.set("桃花", "桃花山庄");
		room_decode.set("天龙", "大理附近");
		room_decode.set("万劫", "峨嵋附近");
		room_decode.set("武当", "武当附近");
		room_decode.set("武功", "长安一带");
		room_decode.set("侠客", "佛山附近");
		room_decode.set("襄阳", "襄阳附近");
		room_decode.set("逍遥", "襄阳附近");
		room_decode.set("星宿", "天山一带");
		room_decode.set("西域", "西域一带");
		room_decode.set("血刀", "血刀一带");
		room_decode.set("雪山", "雪山附近");
		room_decode.set("扬州", "扬州附近");
		room_decode.set("燕子", "燕子坞附近");
		room_decode.set("终南", "终南一带");
		room_decode.set("重阳", "终南一带");
		room_decode.set("神龙", "北京附近");
*/
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

    message_vision("$n冷冷的扫了$N一眼。", who, me);

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("鸿蒙传说", "$0getinfo $1", me);
		AddMenuItem("斩妖除魔", "$0askquest $1", me);
		AddMenuItem("成果报告", "$0report $1", me);
		AddMenuItem("请求失败", "$0fail $1", me);
		SendMenu(me);	
		return 1;
	}
	else
	{
		say("天下太平，无事可做。", me);
		SendMenu(me);
	}

	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "getinfo") == 0)
			return do_gi(me);
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);			
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_gi(CChar * me)
{
		say("劫余老人咳了两声。", me);
		say("劫余老人道：纵横二年，魔王出世，天下大乱，魔族从黑暗中走出来，企图占领大地，将世界归为一元的邪恶。", me);
		say("劫余老人道：宋，金，蒙古，大理，清，倭等人类国家终于被迫消除长久来的敌意，暂时的和平起来。共同对付残酷的敌人。 ", me);
		say("劫余老人道：魔族和人族的战争在第 17 年，已经将要到达尾声，魔族终于被全部逼退到泰山顶上，魔王用魔力制造了一个结界，将泰山封住，并将人类过去死于战争中的英雄的灵魂召唤出来，这些英雄们的灵魂被魔王控制，失去了本性，在泰山里面游荡，只要看见人就会攻击，一时间曾经是万岳朝宗的泰山竟然成为了一座死亡之山。 ", me);
		say("劫余老人道：也就在这个时候，倭国天皇突然间以平分河山为条件和魔王签下合议，一直悄悄保留实力的倭国对人类阵营倒戈一击，并占据了关外，时对中原骚扰，一边是得到黑暗力量帮助的倭国军团，一边是贼心不死的魔族。人类的军队处于两面夹击之中。一时陷入混乱。 ", me);
		say("劫余老人道：但是，真正代表人族的实力的并不是那些国家的军队力量，而是“武侠”。一种在民间流荡的英雄。 ", me);
		say("劫余老人道：侠的意思是“剑人”或“人剑”，尽管他们并不一定都是以剑为武器，但武侠已经成为了他们的统称。 ", me);
		say("劫余老人道：这些“武侠”们都英勇善战，他们按照战斗技术的不同，分为很多个“门派”，每个门派都有他们的独特之处，这些武侠们游走四方，以在不断的战斗中锻炼自己的能力为目标。", me);
		say("劫余老人道：今天，你站在我的面前，我知道你必定也是“武侠”的一员。", me);
		say("劫余老人道：却不知道你是否愿意为斩妖除魔尽一点绵薄之力，同时给自己锻炼？", me);
		SendMenu(me);
		return 1;
}

//返回npc的方位
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(env->query("wiz_room")) return 0;	//巫师房间。
	if(env->query("sleep_room")) return 0;	//休息区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//战斗场景
	if(atoi(env->querystr("owner"))) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	//return room_decode.querystr(env->querystr("area"));
	return env->name(1);
}

int do_aq(CChar * me)
{
	char msg[255];

		static struct {
		char name[40];
		char desc[80];
	}monster[9] = {
		{"小五", "欠了王小二一瓶酒钱"},
		{"丐帮弟子", "撒泼耍赖，骗人钱财"},
		{"不法商人", "强买强卖，欺行霸市"},
		{"乡里恶霸", "偷鸡摸狗，欺压邻里"},
		{"人贩子", "拐卖妇女，天理不容"},
		{"唐门恶少", "打家劫舍，欺男霸女"},
		{"明教弟子", "散播邪教，蛊惑人心"},
		{"朝廷命官", "通敌卖国，残害忠良"},
		{"玩家杀手", "胡乱PK，屠害生灵"},	
	};

		LONG monster_id;

		if (me->query("combat_exp") < 10000)
			return notify_fail("劫余老人道：少年人，不自量力的事还是少做为好……");
		
		if (me->query_temp("fool/finish"))
			return notify_fail("劫余老人道：既已完成任务，为何不向老夫要求回报？");
		
		if ( (monster_id = me->query_temp("fool/doing")) )
		{
			//判断任务是否失败
			CChar * mon = find_npc(monster_id);
			if(! mon)
				return notify_fail("劫余老人怒道：你做事吞吞吐吐，已经错失了良机！");

			const char * area = position_npc(mon);
			if(! area) return notify_fail("劫余老人怒道：你做事吞吞吐吐，已经错失了良机！");

			int diff = me->query_temp("fool/diff");
			tell_object(me, snprintf(msg, 255, "$HIW劫余老人道：有%s在%s%s。\n我不是派你速去除害，泽被天下百姓了吗。还不快去！", monster[diff].name, area, monster[diff].desc));
			return 1;
		}
		else if(me->query("foolmaster"))	//任务丢失
		{
			return notify_fail("劫余老人怒道：你做事吞吞吐吐，已经错失了良机！");
		}
		
		if (me->is_busy())
			return notify_fail("你现在很忙。。。");
	
	//随机找一个NPC的号码

	CNpc * npc = random_npc();

	if(! npc) return notify_fail("竟然没有NPC了。");
	if(npc == this) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//自己竟然就是妖怪。呵呵。
	if(! living(npc)) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//这个NPC快不行了。
	if(DIFFERSTR(npc->querystr("race"), "人类") ) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//非人类NPC
	if(npc->query("monster_lvl")) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//是泰山的随机怪物
	if(npc->query("no_kill")) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//是一般玩家不可能找到的随机怪物
	if(npc->query("mfnpc_lvl")) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//是梦泽山的随机怪物
	
	CContainer * env = npc->environment();

	//现在判断NPC大致的方位
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//这个NPC没有环境
	if(! area[0]) return notify_fail("劫余老人不耐烦的道：过一会再来吧。");	//这个NPC在玩家房间或者战斗中。
		
	int diff = random(9);
	
	//给玩家劫余令
	load_item("jieyuling")->move(me);

	me->set_temp("fool/doing", npc->object_id());	//找到该NPC。
	me->set_temp("fool/diff", diff);			//难度系数
	me->set_temp("fool/name", monster[diff].name);	//
	me->set_temp("fool/where", area);

	me->set("foolmaster", 1);	//接过任务了。
		
	message_vision(snprintf(msg, 255, "$HIW劫余老人对%s说道：有%s在%s%s。\n你速去除害，泽被天下百姓。", me->name(), monster[diff].name, area, monster[diff].desc), me);

	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s接杀%s的%s的任务。", me->name(1), env->querystr("base_name"), npc->name(1)));
		
	return 1;

}

int do_f(CChar * me)
{
//		if (me->query("teapot/fool_finish"))
//			return notify_fail("劫余老人道：既已完成任务，为何还要放弃？");
		
		if(! me->query("foolmaster"))
			return notify_fail("劫余老人喝道：你可曾答应老夫去斩妖除魔？莫要胡闹！");

		CContainer * obj;
		
		if ( (obj=me->present("jieyu ling"))  )
			destruct(obj);
			
		message_vision("$HIY劫余老人怒极大喝：$N你如此不力，让老夫如何对得起天下众生！", me);
		message_vision("$HIY你突闻劫余老人如此大喝，所料不及，被震得眼前金星乱冒，站立不稳！", me);
		
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);

		if(! random(10))
			me->unconcious();
		else
			me->start_busy(30);

		me->delete_temp("fool");
		if(me->query("fool1/count")>10)
			me->add_temp("fool1/count",-10);
		else
			me->delete_temp("fool1/count");
		me->del("foolmaster");
	
		return 1;
}

//给经验
void reward_exp(CChar * me)
{
	char msg[255], tmp[20];
	LONG exp = me->query("level");		

	exp = 100+exp * 3;
	
	//exp = exp * (10 + me->query_temp("fool/diff")) / 10;	//难度系数
	exp = exp + random(me->query_temp("fool/diff") * me->query("level")/10);	//难度系数

	exp = (random(exp) + exp) / 2;
	exp=exp*(1+me->query_temp("fool1/count")/10);
	me->add_temp("fool1/count",1);
	if(me->query_temp("fool1/count")>30)me->set_temp("fool1/count",1);

	me->add("combat_exp", exp);
	int repute=int((random(31)+100)*(10+me->query_temp("fool1/count"))/10);
	me->add("repute",repute);
	tell_object(me, snprintf(msg, 255, "$HIC你获得了%s点经验、%d点江湖声望！", chinese_number(exp, tmp),repute));

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s完成了在%s杀%s的任务，获得%d经验、%d点江湖声望。", me->name(1), me->querystr_temp("fool/where"),me->querystr_temp("fool/name"),  exp,repute));

	me->FlushMyInfo();
}

//向老人请教一级技能
int learn_skill(CChar * me, const char * myskill)
{
	char msg[255];
	CSkill * sk = load_skill(myskill);

	if( !sk->valid_learn(me) ) return 0;

	//玩家的技能经验在总经验中的比重不能超过1/3
	if(me->query("sk_exp") * 3 > me->query("combat_exp"))
		return 0;
				
	//现在计算所需的经验
	LONG need_points =  me->skill_need_points(myskill);
	LONG need_exp = need_points / me->learn_bonus() + 1;
		
	//计算玩家的经验够不够
	if(me->query_valid_exp() < need_exp)
		return 0;
	    
	//计算玩家的技能上限有否达到
	if( strcmp(sk->type(), "martial") == 0 &&
		me->query_skill(myskill, 1) >= CChar::level2skill(me->query("level")) ) 
		return 0;
	
	me->add("sk_exp", need_exp);
	me->improve_skill(myskill, need_points + 1);
	
	me->FlushMyInfo();

	tell_object(me, snprintf(msg, 255, "$HIC%s传授你一级%s！", name(), sk->name(1)));
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s完成了在%s杀%s的任务，获得%s技能一级。", me->name(1), me->querystr_temp("fool/where"),me->querystr_temp("fool/name"),  sk->name(1)));

	return 1;	
}

/*
//给技能
int reward_skill(CChar * me)
{
	CMapping * skills = me->query_skills();
	int count = skills->GetCount();
	if(! count) return 0;

	count = random(count);

	CVector v;
	skills->keys(v);
	return learn_skill(me, v[count]);
}
*/

int do_r(CChar * me)
{
	if (!me->query_temp("fool/finish"))
		return notify_fail("劫余老人道：你尚未完成任务，不要胡闹！");
		
	CContainer * obj;
		
	if (!(obj=me->present("jieyu ling"))  )
		return notify_fail("劫余老人冷冷的道：我给你的令牌呢？");
		
	message_vision("$HIG劫余老人道：好，好！$N，老夫果然没看错人！",me);
	
	reward_exp(me);
	
	destruct(obj);
	me->delete_temp("fool");
	me->del("foolmaster");
	me->start_busy(6);

	return 1;
}

protected:
	CMapping		room_decode;

NPC_END;

//万劫谷石屋



