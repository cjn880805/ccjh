// pub_laozhe.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_laozhe);

virtual void create()
{
	set_name("����", "lao zhe" );

	set("icon", old_man1);
	set("gender", "����" );
	set("age", 70);
	set("long","�����ͷ���麵�̳�������,�������ܺ������ϻ���?");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϴ�ү");
	set_inquiry("��ľ��","��ľ������һ����Ů�����ѵĳ��˶�ħ�����ǧ����ȥ��");
	set_inquiry("÷��","ǧ��Ҫ����÷�������ǻ���");
	set_inquiry("����","����÷��֮�⣬����Ҳ�Ǻܿ��µĹ���");
}

/*
virtual void init(CChar *me)
{
	CContainer * what;
	CNpc::init(me);
	what=load_item("yancao");//�ϵ��̲�
//	sprintf("%s ",what);
//	command("give yancao to",this);  
}
*/

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch( random(2) ) 
	{
	case 0:
		return snprintf(msg,255, "���˼�ͷҲ����˵������λ%s����Ҫ����,С��Ұ�ޡ�",query_respect(ob) );
	case 1:
		return "���˼Ҷ���˵��:��Ҳһ��������,�ͺ���һ��,������кðɡ�";
	}
	return "";
}

/*virtual int accept_object(CChar * who, CContainer * ob)
{ 
if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000)
{
tell_object(who, "��ͷ����˵:�ã��ã����Ǹ��ú��ӡ�");
 who->set_temp("rent_paid",1);
  return 1;
  }
   return 0;
}*/

NPC_END;