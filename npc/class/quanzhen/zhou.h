// quanzhen_zhou.c 周伯通

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhou);

virtual void create()
{
	set_name("周不通", "zhou butong");
	set("gender", "男性");
	set("nickname",  "老顽童"  ) ;
	set("title", "全真教第一代弟子") ;
	set("age", 45);
	set("long","他就是人称「老顽童」的周不通。他本来是全真教掌门人的师弟，武功高强，但现在却被人囚禁在这小小山洞之中，头发胡子长长的，毛茸茸的象一个野人。");
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("icon",old_man1);
	
	set("max_mp", 5000);
	set("mp", 5000);
	set("mp_factor", 0l);
			set("foolid",46);
	set_skill("force", 150);
	set_skill("sword", 100);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 100);
	set_skill("hubo" ,100);
	set_skill("kongming_quan",200);
	map_skill("unarmed","kongming_quan");
	
	create_family("全真教", 1, "弟子");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
 	
	carry_object("cloth")->wear();

	set_inquiry("九阴真经","「九阴真经」就在我床上，你有本事杀了我或把我逼出山洞就可以取走！");
	set_inquiry("黄老怪" ,"他囚了我十五年，总想把我逼出山洞以取「九阴真经」，可他每次来都是扫兴而归！");
	set_inquiry("瑛娘","我、我、、我不认识她！");
	set_inquiry("蛇","不要吓我，我最怕蛇了！");
	set_inquiry("结拜",jie_bai);
	set("no_huan",1);
}

static char * jie_bai(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("gender"), "男性"))
		return "我生平不喜同两种人打交道：一是女人，二是太监。我看你还是趁早请罢！”";
			
	if ( me->query("repute") < -1000)
		return "老顽童哼了一声说：就凭你这种恶人也配与我称兄道弟？！";

	who->say("好！以后我们就是好兄弟了！", me);
	who->say("老哥哥有一套「双手互搏之术」和一路「空明拳」可以传给你作为见面礼哟！", me);
	who->SendMenu(me);	

	me->set_temp("wantong/兄弟", 1);
	who->DownLoad(me);

	return 0;
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(EQUALSTR(arg, "kongming_quan") || EQUALSTR(arg, "hubo"))
		return 0;

	return 1;
}

virtual int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("wantong/兄弟"))
		return 0;
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "du she"))
	{
		message_vision("$N拿出一条毒蛇在老顽童的眼前晃了晃．．．．．．老顽童吓得跳了起来，冲出洞外！边跑边喊：糟糕透了，老玩童这番死定了！声音渐渐远去，终于不复耳闻。" ,who);
		destruct(this);
		return 0;
	}
	return 0;
}
NPC_END;