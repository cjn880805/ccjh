// pub_chuanfu.c �ϴ���
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu);

virtual void create()
{
	set_name("�ϴ���","chuan fu");

	set("icon", old_man2);
	set("gender", "����");
	set("age", 56);
	set("long","����һ���ϴ��򡣱�����˪������͸��һ˿�ƻ�����������������ǰ����ȥ���һ�����������ӵ��һ�Ҵ󴬿��Գ�����");
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	
	set("eff_hp",2000);
	set("hp",2000);
	set("max_mp", 1000);
	set("mp", 1000);
	set("mp_factor", 100);
	
	set_skill("force", 200);
	set_skill("unarmed", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	set_inquiry("�һ���" , "�һ�������һȺ��ħ�������и�С��Ů��������������");
	set_inquiry("����" ,chu_hai);
		
 	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * chu_hai(CNpc * who ,CChar *me)
{
	if (EQUALSTR(me->querystr("family/family_name"), "�һ���"))
	{
        message_vision("�ϴ���һ���֣������������ᴬ��",me);
        message_vision("���ᴬ���$N���˴���һ������ê�����Ϳ����ˣ����ϴ���ȴû�ϴ�......", me);
		tell_object(me, "������ͣ����һ��С���ߡ������´�����" ) ;
		me->move (load_room("�һ�����̲") );//û�иó���
        //me->Move (load_room("dahai"));//�һ�����
        //tell_object(me,  "���ں��Ϻ����˺ܾúܾ�......."  ) ;
		//who->call_out(goto_taohua,10,me->object_id()) ;
       	return "";
	}
	else  
		message_vision("�ϴ����������´�����$Nһ�£�ʲô���������㲻Ҫ���ˣ�������������һ�£�����...�������һ�����ӣ�������Կ��ǡ�",me);
	me->set_temp ("����" , 1 );
	return "";
}

virtual int accept_object(CChar * who, CContainer *ob)
{
	char msg[255];
    if (!who->query_temp("����"))
    {
		message_vision("�ϴ���Ц�Ŷ�$N˵���޹�����»���������Լ����Űɣ�", who);
		return 0 ;
    }

    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000) 
	{
        message_vision(snprintf(msg,255,"�ϴ����$N˵���ã���Ȼ��λ%s��˿������ң�����Ҳƴ�������ƴ�����������ӱ��ˣ�" , query_respect(who)),who);
        who->delete_temp("����" );
        message_vision("�ϴ���һ���֣������������ᴬ��", who);
        message_vision("���ᴬ���$N���˴���һ������ê�����Ϳ����ˣ����ϴ���ȴû�ϴ�......", who);
		tell_object(who, "������ͣ����һ��С���ߡ������´�����" ) ;
		who->move (load_room("�һ���") );
		destruct(ob);
        //who->move(load_room("dahai"));//�һ�����
        //tell_room(who->environment(),snprintf(msg,255,"�ϴ��򿴴����ˣ���������Ľ���Ц�ˣ�ȥ�һ����������������ҿɲ��ɡ�ֻ��ϧ���Ǽ��������Ĵ���Ҫ���ǰ��˸��Ե��ˡ��ٺ٣�������"),who) ;
        //tell_object(who,  "���ں��Ϻ����˺ܾúܾ�......."  ) ;
        //call_out(goto_taohua,10, who->object_id() ) ;
       	return 1;
	}
    else  
		message_vision("�ϴ�����ü��$N˵��������Ҳ̫���˰ɣ�", who);
	return 0;
}

/*
static void goto_taohua (CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)(ob->environment())->Present(param1);

	if(! me) return;

	tell_object(me, "������ͣ����һ��С���ߡ������´�����" ) ;
	me->Move (load_room("/d/taohua/haitan") );//û�иó���
}
*/

NPC_END;