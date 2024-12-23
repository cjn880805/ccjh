// guojing.c 郭靖
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_guojing);

virtual void create()
{
	set_name("靖哥哥", "guo jing");
	set("nickname", "北侠");
	set("gender", "男性");
	set("age", 41);
	set("long", 
		"他就是人称北侠的靖哥哥，既是蒙古成吉思汗的金刀驸马，又是江南七怪、全真派马钰道长、「北丐」和「老顽童」等人的徒弟，身兼数门武功。他身着一件灰色长袍，体态魁梧，敦厚的面目中透出一股威严。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_man4);			//设置人物形象
	
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	
	set("chat_chance", 1);			//设置自动聊天触发率
	set("chat_chance_combat", 20);		//设置NPC使用绝招的几率
	
	set_inquiry("周不通", "你见到我周大哥了？他现在可好？");
	set_inquiry("老顽童", "周大哥一贯这样，没点正经！");
	set_inquiry("洪叫化", "师父除了吃，就是喜欢玩。到处玩，还是为了找吃的。");
	set_inquiry("黄老怪", "那是我泰山大人。他云游四海，神龙见首不见尾的。");
	set_inquiry("二灯大师", "在下对大师好生感激。");
	set_inquiry("白老庄主", "这个老毒物，害死我六位师父，一待襄阳事了，决不与他干休。");
/*	set_inquiry("黄蓉", "蓉儿是我的爱妻，你问她做甚？");*/
	set_inquiry("蓉儿", "蓉儿就是蓉儿了。你问这么多干嘛？");
	set_inquiry("芙儿", "这个女儿，又笨又不听话。");
	set_inquiry("襄儿", "襄儿生于乱世，这辈子又多艰厄。但愿她能快乐一世。");
	set_inquiry("郭虏破", "那是我的小儿子。");
	set_inquiry("过儿", "过儿确实有出息。");
	set_inquiry("马玉", "马道长于我有半师之谊。");	
	set_inquiry("丘在机", "邱道长义薄云天，是真豪杰。");
	set_inquiry("柯辟邪", "那是我大师父。");
	set_inquiry("朱明", "那是我二师父。");
	set_inquiry("韩神龙", "那是我三师父。");
	set_inquiry("南望义", "那是我四师父。");
	set_inquiry("张生", "那是我五师父。");
	set_inquiry("全银达", "那是我六师父。");	
	set_inquiry("韩小青", "那是我七师父。");
	set_inquiry("丐帮", "丐帮英雄几百年了，守卫襄阳多亏了他们。");
	set_inquiry("拜师", "现在蒙古人围攻襄阳，我哪有心情收徒啊！");
//	"job"   : (: ask_job :),
//	"功劳"  : (: ask_gonglao :),
//	"fangqi": (: ask_fangqi :),
//	"放弃"  : (: ask_fangqi :),
//	"奸细"  : (: ask_jianxi :),
	
	
	set("hp", 20000);
	set("max_hp", 20000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 500);
	
	set("combat_exp", 15000000);
	set("score", 500000);

	set("门派/gaibang/wuhui",1);
	set("family/family_name","丐帮");
	set("death_times",99);
	
	set_skill("force", 280);			// 基本内功
	set_skill("huntian_qigong", 280);		// 混天气功
	set_skill("unarmed", 280);			// 基本拳脚
	set_skill("xianglong_zhang", 280);		// 降龙十八掌
	set_skill("dodge", 200);			// 基本躲闪
	set_skill("xiaoyaoyou", 200);			// 逍遥游
	set_skill("parry", 280);			// 基本招架
	
	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("unarmed", "xianglong_zhang");	//设置NPC的基本拳脚装备降龙掌
	map_skill("dodge", "xiaoyaoyou");		//设置NPC的基本轻工装备逍遥游
	map_skill("parry", "xianglong_zhang");		//设置NPC的基本招架装备降龙掌
	set("no_huan",1);
}

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
		return 	"郭靖叹了口气道：“蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....”";
	case 1:
		return 	"郭靖说道：“华筝公主近来不知可好，抽空一定要回大漠去看看她。”";
	}	
	return 0;
}

virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("unarmed xianglong", 1);	//降龙掌的绝招
		break;
	case 1:
		perform_action("force recover", 0);	//自动吸气
		break;
	case 2:
		perform_action("unarmed wuhuei", 1);	//降龙掌的绝招
		break;
	}	
	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "藏宝图") && EQUALSTR(ob->querystr("base_name"), "cang bao tu") )
	{
		if(me->query("xkd/lingjiu") && me->query("xkd/gumu") && me->query("xkd/mingjiao") && me->query("xkd/ry")
			&& me->query("xkd/huashan") )
		{
			//开始比试，如胜利则可以获得去侠客岛的资格，目前暂时不开放
			tell_object(me, "\n$HIC郭靖说道：“赏善罚恶令的确在我这里，你要想拿到的话，先拿出点本事给我看看。”");
			destruct(ob);
			return 1;
		}
		else
			tell_object(me, "\n$HIC郭靖说道：“凭你现在的江湖资历，还没有资格来和我谈这个。”");
	}
	return 0;
}

NPC_END;
