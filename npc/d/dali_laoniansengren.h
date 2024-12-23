//laoniansengren.h
//code by zwb
//12-16
//inherit F_DEALER;

VENDOR_BEGIN(CNDaLi_laoniansengren);

virtual void create()
{
	set_name("����ɮ��","lao nian seng ren");

	set("gender", "����" );
	set("age", 80);
	set("long","���������ƹ��̻��ɮ�ˡ�");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "��ɮ");
 	set("icon",old_monk);

	carry_good("xiang",20);

	set_inquiry("һ��ָ" ,ask_me);
 
	carry_object("c_jiasha")->wear();
}

virtual char * greeting(CChar * me)
{
	char msg[255];

	return snprintf(msg,255,"����ɮ��Ц�����˵������λ%s������ɡ�",query_respect(me));
}

static char * ask_me(CNpc * this_object , CChar * this_player)
{
	if(this_player->query_temp("marks/ask_tempyyz")==1)
	{
		this_player->add_temp("marks/ask_tempyyz",1);
		return "��ȥ���������˰ɣ���Ҳû�м�������˵�������˿�����";
	}
	this_player->set_temp("marks/ask_tempyyz",0l);
	return "ʲô�����Ҵ����ˣ��Ҵ�û��˵����";
/*
	if(this_object->query_temp("mark/ask_temp2"))
	{
		this_object->set_temp("mark/ask_temp3",1);
		return "��ʧ�Ե����������ҿ���һ����Ӱ���������ˡ���";
	}
	else
		return "�����˵�˵�ʲô����";
*/
}

VENDOR_END;
