//xiake.h

#define XIAKE_BEGIN(npc_name)	class npc_name : public CNxiake	{	public:	npc_name(){};	virtual ~npc_name(){};
#define XIAKE_END		};	

NPC_BEGIN(CNxiake);

static char *  ask_zhou(CNpc * npc , CChar * player)
{
	return "���Ǳ������еĶ���������Ҫ��һζ'�ϳ����Ǹ��Ĳ�'����,Ҫ������Ч�������������ֲ�ÿʮ��ſ�һ�λ������������������һ���˺��ѵõ��ģ�С�ֵ���Ҫ��Ҫ�����Ե���ˣ�";
}

virtual int accept_object(CChar * player , CContainer * ob)
{
        CContainer * obn;

        if (  DIFFERSTR(ob->querystr("id"), "shane bu") && DIFFERSTR(ob->querystr("id"), "fuxin cao"))
        {
			say("�ⲻ������Ҫ��ѽ��",player);
			SendMenu(player);
            return 0;
        }

        if ( EQUALSTR(ob->querystr("id"), "shane bu" ))
        {
		    if(query_temp("cao"))
            {
				destruct(ob);
				message_vision("��ϲ��λС�ֵ���!",player);
                obn=load_item("zhou");
                obn->move(player);
                delete_temp("bu");
                delete_temp("cao");
                return 1;
            }
		    else if(query_temp("bu"))
			{
			    say("���Ʒ��������ˡ�",player);
			    SendMenu(player);
			    return 0;
			}
		    else
			{
				destruct(ob);
				say("����ֻ��Ĳ��ˡ�",player);
				SendMenu(player);
				set_temp("bu",1);
				return 1;
			}
        }

        if ( EQUALSTR(ob->querystr("id"), "fuxin cao"))
        {                
			if(query_temp("bu"))
            {
				destruct(ob);
                say("��ϲ��λС�ֵ���!",player);
				SendMenu(player);
                obn=load_item("zhou");
                obn->move(player);
                delete_temp("cao");
                delete_temp("bu");
                return 1;
            }
            else if(query_temp("cao"))
            {
                say("���Ĳ����Ѿ����ˡ�",player);
				SendMenu(player);
                return 0;
            }
            else
            {
				destruct(ob);
                message_vision("����ֻ�����Ʒ����ˡ�",player);
                set_temp("cao",1);
                return 1;
            }           
        }

        return 1;
}

virtual void attempt_apprentice(CChar * player)
{
    message_vision("$Nҡ��ҡͷ��",player);
    say("���ǲ��յ��ӵģ�����Ե�ʯ������ѧ�ۣ�");    
}

NPC_END;
