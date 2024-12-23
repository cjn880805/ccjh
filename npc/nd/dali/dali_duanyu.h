// dali_duanyu.h 段誉
//sound 2001-07-16

NPC_BEGIN(CNdali_duanyu);

virtual void create()
{
	set_name("段玉", "duan yu");
	set("nickname", "大理王子");
	set("gender", "男性");
	set("age", 20);
	set("long", "他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
	set("attitude", "peaceful");
	
	set("str", 12);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",young_man1);	
	
	set("chat_chance", 1);
	
	set_inquiry("大理", "大理是个好地方，山清水秀，风景宜人。");	
	set_inquiry("王嫣甜", "唉，她心里只有她表哥，从来就没把我放在眼里。");
	set_inquiry("拜师", "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。");
	
	set("hp", 5000);
	set("max_hp", 5000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor",300);
	
	set("combat_exp", 2000000);
	set("shen_type", 1);
	
	set_skill("force", 220);		// 基本内功
	set_skill("beiming_shengong", 220);	// 北冥神功
	set_skill("finger", 220);		// 基本指法
	set_skill("six_finger", 220);		// 六脉神剑
	set_skill("dodge", 220);		// 基本躲闪
	set_skill("lingboweibu", 250);		// 凌波微步
	set_skill("parry", 180);		// 基本招架
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "six_finger");
	map_skill("finger", "six_finger");
	prepare_skill("finger","six_finger");
	
	carry_object("gangjian");
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char * chat_msg()						//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
		return 	"段玉叹了口气道：“好久没与箫大哥一起喝酒了，不知道他最近如何？”";
	case 1:
		return 	"段玉叹了口气道：“唉……何时能再见到语嫣啊……”";
	}
	return 0;
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_2") && !me->query_temp("xy/renwu1_21")) 
	{
		tell_object(me,"\n$HIC段玉痴痴的望着东方远处，口中喃喃自语：");
		tell_object(me,"$HIC“凌波微步，罗袜生尘……转盼流精，光润玉颜。含词未吐，气若幽兰。华容婀娜，令我忘餐。");
		tell_object(me,"$HIC唉，不知道王姑娘现在怎样了。”\n");
		tell_object(me,"$HIC段玉叹了口气道：");
		tell_object(me,"$HIC“肩若削成，腰如红素，延颈秀项，皓质呈露，芳泽无加，铅华弗御。");
		tell_object(me,"$HIC云髻峨峨，修眉连娟。丹唇外朗，皓齿内鲜……");
		tell_object(me,"$HIC神仙姐姐，对我有再造之恩，而我却将她的遗物弄得支离破碎，真是万死莫赎。”\n");
		me->set_temp("xy/renwu1_21",1);//段誉需要帛卷
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "帛卷") && EQUALSTR(ob->querystr("id"), "bojuan")
		&& who->query_temp("xy/renwu1_2") && !who->query_temp("xy/renwu1_3") )
	{
		destruct(ob);
		tell_object(who,"\n段玉大喜过望，他小心翼翼地将“帛卷”收进了怀中，然后感激地向你问及来意！");
		tell_object(who,"你将前事一一向段玉说明，并询问关于茶花“红装素裹”之事。\n");
		
		CContainer * bot = load_item("baozi");
		bot->set_name("花种", "hua zhong");
		bot->set("long","这是一粒黑色的种子。");
		bot->set("value", 1);      
		bot->set("unit", "粒");
		bot->move(who);
		tell_object(who,"段玉取出一颗花种交给你。");
		tell_object(who,"段玉说道：“只有河西镇的$HIC石甘露石姑娘$COM方能将此种育成。”\n");
		who->set_temp("xy/renwu1_3",1);//拿到段誉给花种
		return 1;
	}
	return 0;
}
NPC_END;