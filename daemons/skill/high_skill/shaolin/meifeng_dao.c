// meifeng_dao.c 梅峰刀法
//code by Teapot
//date : 2001-03-05

SKILL_BEGIN(CSmeifeng_dao);

virtual void create()
{
	set_name("梅峰刀法");

	Magic_t * magic;
	magic = add_magic("pwrhit", do_pwrhit);
	magic->name = "抽刀断水";
	magic->mp = 1800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	char msg[255];
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
	}action[7] = {
		{"$N左手结狮子印，$w幻化成十九道电芒，交错飞激而去！", 100,25 ,100, 0,},
		{"$N的左脚缩至右脚跟后，风一般的旋身，$w侧劈如电而过！", 300,20 , 200,60,},
		{"$w刀立如松，神奇的做着小幅度的摇摆，形成一片刀幕，“叮叮”作响！", 500,15 ,300, 120,},
		{"$N轻轻发出一声禅唱，将十二重的般若无相真力贯入$w内，举倒横架，“当！”的一声！。", 700,10 ,400, 180,},
		{"$w交错纵横，形成奔腾的刀浪，气流飞荡！", 900,5 ,500, 240,},
		{"$w凛冽的刀气突然爆发，充斥了整个的空间，灿烂如正月的烟花！", 1100,0 ,700, 300,},
		{"$w缓缓的侧扬，温柔得象情人张开的怀抱。", 2000,-95 , 2000,360,},
	};
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("meifeng_dao", 1))
		{
			level = Random(i);
//			snprintf(msg,255,"$N一式%s",action[level].action);
//			m_actions.set("action", msg);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			m_actions.set("parry", action[level].dodge);		// the same as dodge.
			break;
		}
	}
	
	if (me->query_temp("teapot/qijue"))
	{
			level=me->query_temp("teapot/qijue")-1;
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "blade") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 3500)
		return notify_fail("你的内力不够。");
	if (DIFFERSTR(me->querystr("family/master_id"), "jiang yu"))
		return notify_fail("回风七绝只能向江愚学习。");////////////////////////////////////////////////////
	if (me->query_skill("wuying_jian", 1) < 199)	// 200->(die)->199:Can learn.
		return notify_fail("你的回风拂柳剑火候太浅。");
	if (me->query_skill("linji_zhuang", 1) >= 200)	// 200->(die)->199:Can Learn. Appr need 200 lv.
		return notify_fail("你的临机十二庄火候太深。");
	if (me->query_skill("linji_zhuang", 1) < 199)	// 200->(die)->199:Can Learn. Appr need 200 lv.
		return notify_fail("你的临机十二庄火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("未曾斩情灭性，不能自练回风七绝！");
	// Disable Practice.
}

//perform 

static int do_mixhit(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("情天难补只能在战斗中使用。");
	
	if (! (weapon = me->Query_Weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("情天难补无法使用。");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "huashan_sword"))
		return notify_fail("必须配合华山剑法使用。");

	if (me->query_skill("huifeng_jian", 1) < 199)	// 200->(die)->199:Can learn.
		return notify_fail("你的回风拂柳剑火候太浅。");
	if (me->query_skill("huifeng_qijue", 1) < 320)	// 200->(die)->199:Can learn.
		return notify_fail("你的回风七绝火候太浅。");
	if (me->query_skill("linji_zhuang", 1) >= 200)	// 200->(die)->199:Can Learn. Appr need 200 lv.
		return notify_fail("你的临机十二庄火候太深。");
	if (me->query_skill("linji_zhuang", 1) < 199)	// 200->(die)->199:Can Learn. Appr need 200 lv.
		return notify_fail("你的临机十二庄火候太浅。");
		
	int i;

	i=me->query_skill("huifeng_qijue",1);

	if( me->query("mp") < 1800 )		// 七剑１８００ＭＰ。
		return notify_fail("你的真气不够！");

	if (userp(me))
	{
		me->add("mp",-1800);
		me->set("mp_factor",0);
	}

	snprintf(msg ,255,"%s终于静止，似乎在千万年的疲倦后归于无，绝望中隐藏着无限杀机。",weapon->querystr("name").c_str());
	message_vision(msg,me);

	i = (400 - i)/10;
	if(i < 1) i = 1;

	me->call_out(remove_effect, i, target->Query(OBJECTID), i);
		
	me->start_busy(99);
	
	return 1;
	
}



static void remove_effect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->Environment())->Present(param1);
	CContainer * weapon;
	char msg[255];

	me->start_busy(1);

	if( !target || !me->is_fighting(target) )
		return ;
	
	if (! (weapon = me->Query_Weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return ;

	if(! living(me))
		return ;

	snprintf(msg ,255,"%s突然动了……",weapon->querystr("name").c_str());
	message_vision(msg, me);

	for(int n = 0; n < 7; n++)
	{
		me->set_temp("teapot/qijue",n+1);
		Do_Attack(me, target, TYPE_QUICK);
	}

	me->delete_temp("teapot/qijue");
}

SKILL_END;

/*
回风七绝
第一式　　豆蔻青梅

伽蓝剑的剑光象绽放的春花，从记忆的深处飘来，无所迹，无所踪。
他左手结狮子印，阿难刀幻化成十九道电芒，交错飞激处，剑芒消散。

依稀，他又见到那条小河。那天，他刚刚和一群顽童战罢，英雄似的来到河边，准备洗个痛快。却发现一个小小的女孩子撩起了洁白的花裙，正在河里戏水，水花激荡下，她“咯咯”的笑，阳光照得她的笑容透明似的。
她抬起头，看见了他，冲他笑了笑。
他傻乎乎地问：“你在做什么？”
“我在抓鱼啊！”她闭上眼，陶醉的样子，“我最爱吃鱼了，娘说我是属猫的。”
“那……以后我就叫你小猫好不好？”
“好啊！”她微笑着说。

第二式　　心有灵犀

伽蓝剑的剑光突然收敛，忽而又似穿透了时间和空间，魔幻般的直指他的胸膛。
他的左脚缩至右脚跟后，风一般的旋身，阿难刀侧劈如电，格开这凶厉的一剑。

她的名字不是小猫。云碧琼，是关中第一剑云幕天的唯一掌珠。但这并不妨碍他们成为要好的一对。
他们一起采花摘果，捉蟹捕雀，让清脆稚嫩的笑声响遍了山谷。他也是她的保护神，只要和她在一起，她便不再受别的孩子的欺负。他们既是最好的朋友，又象是一对兄妹。
直到那一天，他为她兴冲冲的插上一朵刚摘下来的百合时，见到那漆黑的秀发和白皙修长的玉颈，心中突然一阵茫然。
她等了半天，不耐烦的转过头来，见到他的眼神，心中一颤，不由低下了头。
于是，他们知道，一切都变了。

第三式 金风玉露

伽蓝剑似左还右，剑光抖动处，突然幻成了两道剑影，同时分刺他的小腹和右肩，让人无从分辨。
阿难刀刀立如松，神奇的做着小幅度的摇摆，形成一片刀幕，“叮叮”响声中，两剑无功而返。

星光下，她笑倒在他的怀里。他放肆的吻她，直至她窒息。然后他问：“又做了什么恶作剧了？这么高兴？”
她又笑了一回，才道：“那个王公子，哈，真是个草包！看见我舞了一回云箫十二剑，脸都青了，没等媒婆发话，就转身灰溜溜的走了……”
“人家是读书人嘛！你呀，就会捉弄人！”他责备道。
“难道他不该捉弄？难道你想让我嫁给他？”她气得撅起了小嘴。
“对，对，该捉弄，云碧琼在这世上能嫁的人只有一个，那就是我薛寒山。”
“想傻了你的心了，你！”她用力的捶着他的肩头，可只捶了一下，唇儿早已被封了。
半晌，她才微喘着道：“下个月，爹爹要在岳阳迎战冀南剑魔肖仲海，我们又可以多一些时间在一起了。”
“你爹会赢吧？”他担心的问。
“当然，爹一定会赢的，他是这世上最好的剑手！”她坚定的道，眼中闪烁着崇敬的目光。

第四式 梦断巫山

伽蓝剑蓦地回缩，挽了斗大的一个剑花后，突然化轻灵为刚厉，当头疾劈而下，势重千钧！
他轻轻发出一声禅唱，将十二重的般若无相真力贯入阿难刀内，举倒横架，“当！”的一声，火花四溅下，刀剑呻吟着分离。

“你真的要入峨嵋派？”他焦急的问。
她紧紧的抿着唇，肯定的点了点头。
“可就算你真的入了峨嵋派，她们也未必肯传你回风七绝啊！”
她猛的转身，激烈的道：“无论如何，我一定要完成爹的遗愿，所以，我一定要学回风七绝！”
“这世上还有许多的绝学，何必非要学回风七绝呢？你知道，回风七绝是峨嵋派的镇山绝技，一向不传俗家弟子的！”
她眯起双眼，缓缓道：“爹临终前说过，只有峨嵋的回风七绝能破肖仲海的相思剑法，爹的话决不会错，为了我云家的盛名，爹的血仇，我情愿出家！”
“那我们呢？”他绝望的道。
她抬头细细看他的样子，似乎要把他记住一生一世。
然后她道：“请你忘了我，好吗？”
月光下，她的脸色格外苍白。

第五式 万古寸灰

伽蓝剑呼啸着划出一个个剑圈，山一般压迫过来，让人无处可避。
阿难刀交错纵横，形成奔腾的刀浪，气流飞荡下，拒剑山于丈外

他疲倦的坐在泻玉泉旁，双目通红，他已在这里等了三天三夜。
终于，他听到了那熟悉的脚步声。他精神一振，腾身而起。
果然，他看到了她，尽管她穿了一袭朴素的青袍，走在一群女尼中，他仍一眼认出了她。
“碧琼！碧琼！”他惊喜的呼唤她的名字，“你看，我已经被少林的惠方大师收为弟子了，他说我的阿难刀一定能战胜肖仲海的相思剑。我们可以为你爹报仇了，你也不用学那回风七绝了！”
一个年纪极少的小尼好奇的问：“定真师姐，这是谁呀？”
她冷冷的望着他，缓缓道：“我不认得这位施主。”
他刚想冲过去，“仓啷”声中，女尼们长剑纷纷出鞘，齐声喝道：“峨嵋圣地，施主自重！”
他呆呆的看着她渐渐远去。

第六式 生死冥河

伽蓝剑的剑光似银河飞瀑，澎湃如雪，势不可挡的向他倾泻而来！
阿难刀凛冽的刀气突然爆发，充斥了整个的空间，剑光与刀气相撞下，灿烂如正月的烟花！

静灭老尼缓缓的将手中的信放下，沉思不语。
“师太……”他期待的道。
“施主既然诛杀了彩虹燕子高飞青，保全了我峨嵋弟子的清白，有恩与敝派，又有少林惠方大师的手书，你的要求我本应应允才是，只是……”
他的心仿佛浸入了雪水里。
“定真的天赋极好，乃是百年来首个在三十岁前就将峨嵋的碎玉神罡练至第九重天的弟子，更何况她又是本派第一个将三年内回风七绝全部练成的剑道天才！”
他木然无语。
“不过，敝派一向恩怨分明，为了报答施主的大恩，就给施主一个机会……”
他猛的抬头。
静灭老尼的脸上浮现出一丝狡黠的微笑：“下月十八日，敝派举行论剑大会，请施主只身独剑再到敝派，只要施主能接下定真的回风七绝，贫尼做主，答应定真下山！”

第七式 情天难补

伽蓝剑终于静止，似乎在千万年的疲倦后归于无，绝望中隐藏着无限杀机。
阿难刀缓缓的侧扬，温柔得象情人张开的怀抱。

“大哥，回风七绝真的无招可破吗？”他问。
“回风七绝，绝在第七……”韩笑啜了口手中的热茶，脸上露出凝重之色，“自从两百年前斩情师太首创回风七绝，这第七式‘情天难补’就始终没人能破得了。”
“那你呢，你能破吗？”他满怀希望的望着这位义兄。
“不能……”
他的心猛的一沉。
韩笑大有深意的瞟了他一眼：“虽然不能破，但以我刀法中最凌厉的一招‘抽刀断水’，却可以和对方拼个两败俱伤。只是，你要学吗？”

伽蓝剑终于动了，就象天边的流星划过，那么寂寥冷漠的刺向他的胸膛，如此无助的一剑！如此伤心的一剑！如此黯然的一剑！
一边观战的静灭老尼嘴角泛起一丝笑意。那个小尼却担心的“啊！”了一声，不想见这个英气勃勃的少年这样折在剑下。
没有人知道公认的天下第一用刀高手韩笑是他的义兄，没有人知道韩笑的“抽刀断水”可以与“情天难补”平分秋色！
阿难刀没有动。
伽蓝剑刺入他的胸膛！
他深深的看进她的眼内，轻轻的呢喃道：“小猫……”
伽蓝剑入体一寸，嘎然而止！
她那样定定的看了他好久，突然热泪盈眶，扑入他的怀里。
伽蓝剑跌落尘埃。
他紧紧的拥着她，似乎一松手，她就会消失在这红尘里。
她捂住他的伤口，泪眼迷蒙的问他：“痛不痛？”
他爱怜的摇了摇头，抬起头，向面色铁青的静灭老尼缓缓道：“情天仍然可以用情来补。”
然后，两人依偎着走下山去。
夕阳为两人的身影镀上了一道明艳的金边，晚风吹拂，衣袂飘飘，远远望去，恍若神仙中人。
那小尼目送着两人静静的远去，心思起伏下，不由瞧得痴了。 

*/