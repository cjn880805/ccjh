// pub_qianlong.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_qianlong);

virtual void create()
{
	set_name("乾隆皇帝",  "qian long");

	set("icon", young_man1);
	set("title", "清高宗");
	set("gender", "男性");
	set("age", 43);
	set("per", 24);
	set("long","乾隆皇帝姓爱新觉罗，名弘历，是大清入关后第四位在位皇帝，生平号称有十大武功，自称“十全老人”。");
	set("combat_exp", 500);
	set("attitude", "piece");
	
	carry_object("cloth2")->wear();
	carry_object("youlongsword")->wield();
	add_money( 3000);
}

/*
virtual void init(CChar *me)
{
	add_action("do_kneel", "kneel");
}
int do_kneel()

virtual char *greeting(CChar *me)
{
//	int i;
//	CChar * chen;
	char msg[255];
	
	if (  (me->environment())->present("chen jialuo") )
	{
		message_vision("$N正想给乾隆皇帝请安，却被陈居阳一把拦住：鞑子的鹰犬，不要脸的奴才，纳命来吧！ ", me);
		kill_ob(me);
		chen = all_inventory(me->environment());
		for(i=0; i<sizeof(chen); i++)
		{
			if( chen[i] -> query("id") == "chen jialuo")
				chen[i]->kill_ob(me);
		}
	}
	message_vision(snprintf(msg,255,"$N恭恭敬敬地跪了下来，磕头道：奴才%s救驾来迟，皇上恕奴才死罪！ ",me->name() ), me);
	if( me->query("combat_exp") < 150000 )
	{
		message_vision("$n看着$N，哼了一声：你胆敢欺君冒功！凭你这点能耐也想挑了红花会？！ ", me, this );
		message_vision("$n飞起一脚，踢得$N丫手丫脚滚下六和塔去了。 ", me, this );
		me->move(load_room("liuheta") );//杭州六和塔
		tell_object(me,  "你从塔顶被一脚踢了下来，好疼！还受了伤。" );
		
		tell_room( me->environment(),snprintf(msg,255,"只见%s从塔顶上扑通一声跌了下来，躺在地上半天爬不起来！" ,me->name() ), me);
		
		me->receive_wound("hp", 20);
		me->add("combat_exp", 0 - me->query("combat_exp") /100);
		return "";
	}
	if( me->query("marks/qianlong") )
	{
		message_vision(	"$n看着$N，哼了一声，没理$N。 ", me, this );
	}
	else
	{
		message_vision("$n看着$N说道：免了！看在你救驾有功，免你死罪，朕自有封赏。 ", me, this );
		me->set("marks/qianlong", "1");
		me->add("combat_exp", 10000);
	}
	return "";
}
*/

NPC_END;