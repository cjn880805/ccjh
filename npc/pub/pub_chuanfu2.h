// pub_chuanfu2.c �ϴ���
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu2);

virtual void create()
{
	set_name("�ϴ���2","chuan fu2");

	set("icon", old_man1);
	set("gender", "����");
	set("age", 56);
	set("long",	"����һ���ϴ��򡣱�����˪������ʲôҲ����������");

	set("combat_exp", 1000000);
	set("shen_type", 1);

	set("str",800);

	set("max_mp", 100);
	set("mp", 100);
	set("mp_factor", 500);

	set_skill("force", 100);
	set_skill("unarmed", 300);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 2000)
	{
        message_vision(snprintf(msg,255,"�ϴ����$N˵���ã���λ%s���ϴ��ɡ�" ,query_respect(who) ), who);
		tell_object(who, "�ɴ����ڵ����ˡ������´�����" ) ;
		destruct(ob);
		//me->Move (load_room("������ͷ1")) ;//û�иó���
        
		//who->Move (load_room("/d/city/duchuan"));//û�иó���
		//call_out(goto_matou1, time, who->object_id()) ;
       	return 1;
	}
    else  
		message_vision("�ϴ�����ü��$N˵��������Ҳ̫���˰ɣ�", who);
	return 0;
}

/*
static void goto_matou1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);

	if(! me) return;
	tell_object(me, "�ɴ����ڵ����ˡ������´�����" ) ;
	me->Move (load_room("/d/shaolin/matou1")) ;//û�иó���
}
*/
NPC_END;