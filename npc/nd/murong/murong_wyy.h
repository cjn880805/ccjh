//wyy.c
//sound 2001-07-16

NPC_BEGIN(CNmurong_wyy);

virtual void create()
{
	set_name("王语甜", "wang yuyan");
	set("long", "她生得极为美貌,一双眼睛顾盼生辉。");
	set("nickname", "天下无不知");
	set("gender", "女性");
	set("age", 20);
	set("attitude","friendly");
	set("str", 10);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("per", 35);
	set("icon",young_woman1);
	
	set("max_hp", 500);
	set("hp", 500);
	
	carry_object("cloth")->wear();
}
/*
void init()
{
	add_action("lingwu","ask");
}

int lingwu(string arg)
{
	object me=this_player(), ob = this_object();
	string special;
	int bl, sl;
	string name;
	
	if (!sscanf(arg, "%s about %s", name, arg)) return 0;
	if (!id(name)) return 0;
	
	if (!me->query("luohan_winner")) return notify_fail("你级别不够，不能在此领悟。\n");
	write("你向"+name()+"请教关于「" + to_chinese(arg) + "」的疑问。\n");
	if (!(special=me->query_skill_mapped(arg))) {
		if (arg == to_chinese(arg))
			write(name()+"说道：「" + arg + "」是什么武功？怎么我没听说过？\n");
		else
			write(name()+"说道：我只能从你的特殊技能中给你指点。\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting()) {
		write(name()+"说道：你正忙着呢。\n");
		return 1;
	}
	if (!me->query_skill(arg,1)) {
		write(name()+"说道：你不会这种技能。");
		return 1;
	}
	if( arg == "force") {
		write(name()+"说道：我不能指点你的基本内功。\n");
		return 1;
	}
	if((int)me->query("potential") < 200 ) {
		write(name()+"说道：你的潜能太少了。\n");
		return 1;
	}
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("hp") < 50) {
		me->receive_damage("jing",bl/5);
		write(name()+"说道：" + RANK_D->query_respect(me) + "先休息一下吧。\n");
		return 1;
	}
	sl=me->query_skill(special,1);
	if (bl > sl) {
		write(name()+"说道：" + RANK_D->query_respect(me)
			+ "的"+to_chinese(special)+"造诣不够，我不能指点你更深一层的"+to_chinese(arg)+"。\n");
		return 1;
	}
	write("你听了" + name() + "的指点，对"+to_chinese(arg)+"的体会又深了一层。\n");
	if ((int)me->query("combat_exp",1) >850000){
		me->receive_damage("jing",bl/5*3);
		me->add("potential", -8);
		me->improve_skill(arg, me->query_int()*3/2);
		return 1;
	}
	me->receive_damage("jing",bl/5*2);
	me->add("potential", -random(6));
	me->improve_skill(arg, me->query_int()*3/2);
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	command("peace " + ob->query("id"));
}
*/
NPC_END;