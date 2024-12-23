// shenlong_hong.c �鰲ͨ

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;
//inherit F_MASTER;

NPCSHENLONG_BEGIN(CNshenlong_hong);

virtual void create()
{
	set_name("�鰲ͨ",  "hong antong");
	set("title",  "�����̽���" );
	set("nickname",  "�����ɸ�" );
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲ͨ�� ");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
 	set("icon",old_man2);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 200);
	set_skill("shenlong_xinfa", 200);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("unarmed", 200);
	set_skill("strike",400);
//	set_skill("shenlong_quanfa", 200);		//û�иü��� lanwood 2000-12-29
	set_skill("parry", 150);
	set_skill("staff", 200);
	set_skill("shedao_qigong", 180);
	set_skill("literate", 100);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
//	map_skill("unarmed", "shenlong_quanfa");
	map_skill("parry", "shedao_qigong");
	map_skill("staff", "shedao_qigong");
	
	set_inquiry("���"," һ�������벻���������̵�");
	set_inquiry("�鰲ͨ"," �㲻������ǲ���? ");
	set_inquiry("����"," �Ҿ��������̽���. ");
	set_inquiry("�ں�"," ���겻��!�����ɸ�!��������!������ʥ! ");
	
	set("chat_chance_combat", 50);  
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	add_money( 5000);

}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))          
			set("combat_exp",500000);
		set("hp",10);
	}
	return "";
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	if (strcmp(comm,"join") == 0)
		return do_join(me,arg);

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !me->query_temp("pending/flatter") )
		return 0;
	if( !strlen(arg)) return notify_fail("��˵��ʲô�� ");
	me->delete_temp("pending/flatter");

	message_vision(snprintf(msg,255,"$N����˵����%s", arg), me);

	if( strstr(arg, "���겻��")
		&&( strstr(arg, "�����ɸ�") 
		|| strstr(arg, "��������") 
		|| strstr(arg, "������ʥ") ))
	{
		command("smile");
		say(" �⻹��ࡣ ");
		me->set("learnhong", 1);
		command(snprintf(msg,255,"recruit %ld" , me->object_id() ));
	} 
	else
	{
		say(" ����˲����ҷ�����������������㣿!");
		kill_ob(me); 
	}
	return 1;
}

int do_join(CChar *me,char * arg)
{
	char msg[255];

	if(me->query("shenlongjiao")) 
	{
		message_vision( "�鰲ͨ˵�������Ѿ��������̵����ˡ� " ,me);
		return 1;
	}
	if (me->query("repute")>-1000)
	{
		message_vision( "�鰲ͨ��$N��ŭ�����������?һ����Ͳ��Ǻ���! " ,me);
		kill_ob(me); 
		return 1;
	}
	if (me->query_combat_exp() < 20000)
	{
		message_vision( "�鰲ͨ��$Nҡͷ�������ʵս����̫�͡� " ,me);
		return 1;
	}
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1))
	{
		me->set("shenlongjiao",1);
		command(snprintf(msg,255,"tell %ld �����ھ��������̵�����. ", me->object_id() ));
		return 1;	
	}
	else 
	{
		message_vision( "�鰲ͨ��$N��ŭ�����������?һ����Ͳ��Ǻ���! " ,me);
		kill_ob(me); 
		return 1;
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
    if (ob->query_skill("shenlong_xinfa",1) < 80 ) 
	{
        say("��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
    }
    if (ob->query_skill("shedao_qigong",1) < 80 ) 
	{
        say("��ı����ȷ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
    }
    if (ob->query("repute") > -10000  )
	{
        say(" �������������������������������ְ׵�����򽻵�������ذɣ�", ob);
		SendMenu(ob);
		return;
	}
    say(" �ܺã��ܺá�");
    command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}


virtual int prevent_learn(CChar * ob, string arg)
{
	if( ob->query("learnhong")) return 0;
	if (ob->query("repute") > -1000) 
	{
		say("��Խ����Խ��׵������Ե׵ġ�");
		kill_ob(ob); 
		return 1;
	}
	if( ob->query_temp("pending/flatter") ) 
	{
		say("����˲����ҷ�����������������㣿!");
		kill_ob(ob); 
		return 1;
	}
	else 
	{
		say("�Һ鰲ͨ�������������ʥ����ô������");
		message_vision("�鰲ͨ΢��˫�ۣ������룬һ��������������ӡ� ",ob);
		ob->set_temp("pending/flatter", 1);
		return 1;
	}
}

virtual int recognize_apprentice(CChar *ob)
{
	if( ob->query("learnhong")) return 1;
	return 0;
}

NPCSHENLONG_END;