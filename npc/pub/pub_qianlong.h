// pub_qianlong.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_qianlong);

virtual void create()
{
	set_name("Ǭ¡�ʵ�",  "qian long");

	set("icon", young_man1);
	set("title", "�����");
	set("gender", "����");
	set("age", 43);
	set("per", 24);
	set("long","Ǭ¡�ʵ��հ��¾��ޣ����������Ǵ�����غ����λ��λ�ʵۣ���ƽ�ų���ʮ���书���Գơ�ʮȫ���ˡ���");
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
		message_vision("$N�����Ǭ¡�ʵ��밲��ȴ���¾���һ����ס�����ӵ�ӥȮ����Ҫ����ū�ţ��������ɣ� ", me);
		kill_ob(me);
		chen = all_inventory(me->environment());
		for(i=0; i<sizeof(chen); i++)
		{
			if( chen[i] -> query("id") == "chen jialuo")
				chen[i]->kill_ob(me);
		}
	}
	message_vision(snprintf(msg,255,"$N���������ع�����������ͷ����ū��%s�ȼ����٣�����ˡū����� ",me->name() ), me);
	if( me->query("combat_exp") < 150000 )
	{
		message_vision("$n����$N������һ�����㵨���۾�ð����ƾ���������Ҳ�����˺컨�᣿�� ", me, this );
		message_vision("$n����һ�ţ��ߵ�$NѾ��Ѿ�Ź���������ȥ�ˡ� ", me, this );
		me->move(load_room("liuheta") );//����������
		tell_object(me,  "���������һ���������������ۣ��������ˡ�" );
		
		tell_room( me->environment(),snprintf(msg,255,"ֻ��%s����������ͨһ���������������ڵ��ϰ�������������" ,me->name() ), me);
		
		me->receive_wound("hp", 20);
		me->add("combat_exp", 0 - me->query("combat_exp") /100);
		return "";
	}
	if( me->query("marks/qianlong") )
	{
		message_vision(	"$n����$N������һ����û��$N�� ", me, this );
	}
	else
	{
		message_vision("$n����$N˵�������ˣ�������ȼ��й���������������з��͡� ", me, this );
		me->set("marks/qianlong", "1");
		me->add("combat_exp", 10000);
	}
	return "";
}
*/

NPC_END;