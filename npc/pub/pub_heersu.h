// pub_heersu.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_heersu);

virtual void create()
{
	set_name("�ն���",  "heersu" );

	set("icon", old_man2);
	set("gender", "����");
	set("age", 65);
	set("long", "����һ���ϲοͣ�����һƶ��ϴ�� ");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	
	set_inquiry("�˲�",ask_me);
	set_inquiry("����",ask_he);
	set("item_count",1);
	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * ask_me(CNpc *who,CChar *me)
{
 	if( (me->query("repute")<0)) 
		return "���������������类�����ˣ�û���ˡ�";
	
	me -> set_temp("�˲�",1);
	return "������ó�Ǯ���ɡ�";
}

static char * ask_he(CNpc *who,CChar *me)
{
 	if( (me->query("repute")<0)) 
		return "�����������������类�����ˣ�û���ˡ�";

	me -> set_temp("����",1);
	return "������ó�Ǯ���ɡ�";
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	CContainer * obj;

    if (! me->query_temp("�˲�") && ! me->query_temp("����"))
    {
		say("�Ҳ���Ҫ���ϵ�Ǯ��", me);
		SendMenu(me);
		return 0 ;
    }

    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 50000)
    {
		if ( me->query_temp("����"))
		{
			if (query("item_count")>0)
			{
				say(snprintf(msg,255,"�ã���Ȼ��λ%s��˿���������ͷ�ӣ�������������˺ܾ��ˣ����͸���ɣ�" , query_respect(me) ),me);
				me->delete_temp("����");
				obj = load_item("shouwu");//������
				obj -> move(me);
				add("item_count", -1);
			}
			else
				say("Ǯ�������ţ�������ʱ��˵�ɣ�", me);
		} 
		else
		{
			if (query("item_count")>0)
			{
				say(snprintf(msg,255,"�ã���Ȼ��λ%s��˿���������ͷ�ӣ���ò������˺ܾ��ˣ����͸���ɣ�" ,query_respect(me)), me);
				me->delete_temp("�˲�");
				obj = load_item("shanshen");//��ɽ��
				obj -> move(me);
				add("item_count", -1);
			}
			else
				say("Ǯ�������ţ���һ���Ҹ�������ɽ�θ�����", me);
		}
    }
    else  
		say("������Ҳ̫���˰ɣ�", me);

	SendMenu(me);
	destruct(ob);
    return 1;
}

NPC_END;