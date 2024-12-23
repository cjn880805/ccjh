//dy_daiyanren.h
//lanwood 2001-11-04

NPC_BEGIN(CNdy_daiyanren);

void create()
{
	set_name("地狱代言人", "daiyan ren");
	
	set("gender", "男性");
	
	set("icon", young_woman1);
	set("level", 20);
	
	set("max_hp", 12000);
	set("max_mp", 3000);
	set("mp_factor", 70);
	
	set("combat_exp", 952800);
	
	set("cast_chance", 20);
	set("nkgain", 1);
	
	set("str", 34);
	set("con", 35);
	set("int", 35);
	set("dex", 22);
	
	set_skill("changquan", 206);
	set_skill("cuff", 206);
	set_skill("guimei_shenfa", 206);
	set_skill("dodge", 206);
	set_skill("hunyuan_yiqi", 206);
	set_skill("force", 206);
	
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 120);
	set("apply/damage", 150);

//	set("18dy/ceshi", 0l);
//	set("18dy/buxihuan", 0l);
}

int do_talk(CChar * me, char * ask = NULL)
{

	AddMenuItem("十八地狱", "$018dy $1", me);
	AddMenuItem("参加测试", "$0ceshi $1", me);
	AddMenuItem("我不喜欢", "$0buxihuan $1", me);
	SendMenu(me);	

	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{

	if(strcmp(comm, "18dy") == 0)
		return do_18dy(me);
	if(strcmp(comm, "ceshi") == 0)
		return do_ceshi(me);	
	if(strcmp(comm, "buxihuan") == 0)
		return do_buxihuan(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_18dy(CChar * me)
{
		
	say("十八地狱是XX同志作梦时不小心留下的一个玩笑"
		"经过若干年的极度痛苦的难产和若干人的热切的等待"
		"终于露出了冰山一角，给大家先睹为快。", me);
	say("听说闯入十八地狱可以增加自己的经验和技能，"
		"有机会去十八地狱，对江湖中的所有人而言都有极大的诱惑力。", me);
	say("十八地狱可以寻找神秘武功和奇异的珍宝。"
		"每一层都有，但85认为那些东西很可怕，暂时不都放出来。", me);
	say("十八的还要经常调整，"
		"人们一进到里面，就变得象疯子一样如痴如醉的修习绝学，"
		"但85保留修改权。", me);
	say("随机宝箱、武功残片，物品奖励、秘密商人暂时不放，"
		"直到无BUG后逐步放出。", me);
	say("好了，你们都进来吧。"
		"哈哈哈哈哈！！！！！！"
		"85死了", me);

	SendMenu(me);
	return 1;
}

int do_ceshi(CChar * me)
{
	
	CContainer * obj = me->PresentName("18qing_tie", IS_ITEM);
	if(! obj)
	{	
		say("好，给你这个请帖，切忌不要丢失。", me);

		SendMenu(me);
		
		load_item("18qing_tie")->move(me);
		add("18dy/ceshi", 1);
		tell_object(me, "$HIY得到请帖。");	
	}
	return 1;
}

int do_buxihuan(CChar * me)
{
		
	say("我不想去十八地狱，85去死吧！", me);

	SendMenu(me);
	add("18dy/buxihuan", 1);
	return 1;
	tell_object(me, "$HIY85：......。");	

}

NPC_END;