NPC_BEGIN(CNPub_nigu1);

virtual void create()
{
	set_name("���1","nigu");

	set("icon", young_nun);
	set("gender", "Ů��" );
	set("age", 22);
	set("long","��λ����������̵��ϣ�˫���������������������дʡ�");
	set("combat_exp", 1000);
	set("attitude", "friendly");

};
virtual char * greeting(CChar * me)
{
	static char msg[255];
	return snprintf(msg,255,"���ʩ��һ��˵������λ%s ����л������Ը���汣�ӡ�",query_respect(me));
}


NPC_END;
