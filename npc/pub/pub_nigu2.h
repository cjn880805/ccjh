NPC_BEGIN(CNPub_nigu2);

virtual void create()
{
	set_name("���","nigu2");
	
	set("icon", young_nun);
	set("gender", "Ů��" );
	set("age", 32);
	set("long","��λ����������̵��ϣ�˫���������������������дʡ� ");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	
	
};
virtual char * greeting(CChar * me)
{
	static char msg[255];
	return snprintf(msg,255,"���ʩ��һ��˵������λ%s ����˴���Ϊ������һ�������ɡ�",query_respect(me));
}


NPC_END;
