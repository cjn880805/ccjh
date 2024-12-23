//kongkong.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_kongkong);

virtual void create()
{
	set_name("�տ�",  "kong kong");
	set("title", "������ؤ");
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);
	set("icon",begger);

	set("hp", 500);
	set("max_hp", 1500);
	
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);

	
    set("startroom","��������Ժ");
	set("thief", 0l);
	set("combat_exp", 80000);

	set_skill("force", 40); 
	set_skill("unarmed", 60);
	set_skill("sword", 50);
	set_skill("dodge", 80);
	set_skill("parry", 50);
	set_skill("stealing", 100);
	set_skill("begging", 100);
//	set_skill("checking", 80); 
	set_skill("xunshou_shu", 80);

	set_skill("huntian_qigong", 40); 
	set_skill("xianglong_zhang", 60);
	set_skill("xiaoyaoyou", 80); 

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");

	create_family("ؤ��", 19, "�˴�����");

	set("chat_chance", 3);
	
	set("chat_chance_combat", 20);
	
	carry_object("jitui");
	carry_object("jiudai");
	add_money(1000);
	set("no_huan",1);
	
}

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�";
	case 1:
		return 	"�տն�������ش��˸���Ƿ��";
	case 2:
		return "�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� ";
	case 3:
		random_move();
		return 0;
	}
	
	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}
/*
virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	say("�ðɣ�ϣ�����ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "beggar");
}
*/
/*
virtual void init(CChar *me)
{	
	CNpc::init(me);
	if( userp(me) ) 
	{
		remove_call_out(stealing);
		call_out(stealing, 1, ob->object_id());
	}
}

void stealing(CChar * ob)
{
	switch( random(5) ) 
	{
	case 0:
		command("hehe " + ob->object_id());
		command("steal coin from " + ob->object_id());
		command("buy jitui");
		break;
	case 1:
		command("grin " + ob->object_id());
		command("steal silver from " + ob->object_id());			
		command("eat jitui");
		break;
	case 2:
		command("hi " + ob->object_id());
		command("steal gold from " + ob->object_id());			
		command("drink jiudai");
		break;
	case 3:
		command("pat " + ob->object_id());
		command("steal changjian from " + ob->object_id());	
		command("wield changjian");	
		command("drink jiudai");
		break;
	case 4:
		command("walkby " + ob->object_id());
		command("steal jitui from " + ob->object_id());	
		command("eat jitui");
		break;
	}
}
*/

virtual int accept_object(CChar * me, CContainer * obj)
{
	char msg[255];
	if (EQUALSTR(obj->querystr("base_name"), "coin") && obj->query("value") >= 1) 
	{
		command("smile");
		say("��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !", me);
		SendMenu(me);
		CContainer * coin = present("coin");
		if(coin)
			command(snprintf(msg,255,"give %ld to %ld 1000", coin->object_id(), me->object_id() ));

		return 1;
	}

	command("shake");
	say("���ֶ������Ҫ ! ��һ��ȥ !", me);
	SendMenu(me);
	return 0;
}

int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s����С������뿪",query_respect(me) ));
	return 0;
}

NPC_END;
