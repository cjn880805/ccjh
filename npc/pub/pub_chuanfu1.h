// pub_chuanfu1.c ����
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu1);

virtual void create()
{
	set_name("����1","chuan fu1");

	set("icon", cateran);
	set("gender", "����");
	set("age", 36);
	set("long", "����һ���ɻ����ϵĴ��򡣱�����˪������͸�������˵ĺ�ˬ��");
	
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set("eff_hp",800);
	set("hp",800);
	set("max_mp", 100);
	set("mp", 100);
	set("mp_factor", 10);
	
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000)
    {
        message_vision(snprintf(msg,255,"�����$N˵���ã���Ȼ��λ%sҪ���������Ҿ��������������ɣ�" ,query_respect(who)), who);
        message_vision("�����$N���˴���һ������ê�������ŷ��밶��......", who);
        //who->Move (load_room("�����ɻ���"));//û�иó���
		tell_object(who , "���ܿ�ͣ���˰�����̧�ſ��������" ) ;
		who->move(load_room("���⴬��"));//���⴬��
		destruct(ob);
        
       	return 1;
    }
    else  
    {
		message_vision("������ü��$N˵������㣿�����Ҹ����ɣ�˵���ͷ�����ˡ�", who);
        destruct(this);
		return 0;
    }
}

NPC_END;