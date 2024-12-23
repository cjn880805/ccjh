// shaolin_zhang1.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_zhang1);

virtual void create()
{
    set_name("���貨", "zhang chengfeng");
    set("nickname",  "��ţ��ħ"  );
    set("title", "������̳���");
    set("gender", "����");
    set("age", 42);
    set("shen_type", -1);
    set("long","����������̳��ϡ�");
    set("attitude", "peaceful");
    set("icon",old_man1);
	
    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3000);
    set("max_mp", 3000);
    set("mp_factor", 300);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);
    set_skill("kuihua_xinfa", 150);
    set_skill("unarmed", 150);
    set_skill("changquan", 150);
    set_skill("dodge", 150);
    set_skill("lingxu_bu", 150);
    set_skill("parry", 150);
    set_skill("club", 150);
    set_skill("weituo_gun", 150);
	
    map_skill("force", "kuihua_xinfa");
    map_skill("club", "wweituo_gun");
    map_skill("parry", "wweituo_gun");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "lingxu_bu");
	
    create_family("�������", 2, "����");
    
    carry_object("shutonggun")->wield();
    carry_object("cloth")->wear();

	set_inquiry("��ľ��", "���̵��ӻ�ֽ������Ʒ������£�");
	set_inquiry("��ľ��","���Ǳ��̽������ƣ���������������٣�");
	set_inquiry("����",shang_ya);
	set("no_huan",1);
}

static char * shang_ya(CNpc *who,CChar *me)
{
    if ( EQUALSTR(me->querystr("family/family_name"), "�������"))
    {
        message_vision("�ų˷�һ���֣���������һ���������",me);
        message_vision("$Nһ�������˵��������������ؽ�����ȥ......", me);

		goto_heimuya(me);

		/*
        me->Move (load_room("/d/heimuya/basket") );//û�иó���
		who->call_out(goto_heimuya, 10, me->object_id() ) ;
		*/

       	return 0;
    }
     
	return "�ų˷��������´�������һ�£�ʲô�����£���ĺ�ľ���أ���";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
    if (EQUALSTR(ob->querystr("id"), "heimu ling"))
    {
        message_vision(snprintf(msg,255,"�ų˷��$N˵���ã���λ%s �����Ǿ���ɣ�" ,query_respect(who) ), who);
        message_vision("�ų˷�һ���֣���������һ���������", who);
        message_vision("$Nһ�������˵��������������ؽ�����ȥ......", who);
        goto_heimuya(who);
       	return 1;
    }
    else  
    {
		message_vision("�ų˷��$N˵�����ˣ�ң���", who);
        kill_ob(who);
    }
    return 0;
}

static void goto_heimuya (CChar * me)
{
	tell_object(me , "����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�");
    me->move (load_room("��ľ�³ɵµ�")); //��ľ�³ɵµ�
}

NPC_END;