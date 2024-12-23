// pub_laozhe.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_laozhe);

virtual void create()
{
	set_name("老者", "lao zhe" );

	set("icon", old_man1);
	set("gender", "男性" );
	set("age", 70);
	set("long","这个老头正抽旱烟抽得上瘾呢,怎样才能和他搭上话呢?");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "老大爷");
	set_inquiry("黑木崖","黑木崖上有一个穿女人衣裳的吃人恶魔，你可千万不能去！");
	set_inquiry("梅海","千万不要得罪梅海，它是坏人");
	set_inquiry("灵蓝","除了梅海之外，灵蓝也是很可怕的怪物");
}

/*
virtual void init(CChar *me)
{
	CContainer * what;
	CNpc::init(me);
	what=load_item("yancao");//上等烟草
//	sprintf("%s ",what);
//	command("give yancao to",this);  
}
*/

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch( random(2) ) 
	{
	case 0:
		return snprintf(msg,255, "老人家头也不回说道：这位%s，不要乱跑,小心野兽。",query_respect(ob) );
	case 1:
		return "老人家对你说到:我也一大把年纪了,就好那一口,你就行行好吧。";
	}
	return "";
}

/*virtual int accept_object(CChar * who, CContainer * ob)
{ 
if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000)
{
tell_object(who, "老头对你说:好，好，真是个好孩子。");
 who->set_temp("rent_paid",1);
  return 1;
  }
   return 0;
}*/

NPC_END;