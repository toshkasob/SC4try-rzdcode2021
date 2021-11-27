#pragma once

#include <ctime>
#include <string>
#include <vector>

class TransporRequestsList {
    std::vector<TransportRequestUnitFull> list_requests;
};

/*! Заявка на автотранспорт
 *
 */
class TransportRequestUnit {
    time_t         time_4_get_vehicle_; //! Дата и время подачи ТС
    unsigned int   passengers_numb_;    //! Количество пассажиров
    float          cargo_volume_; //! Объем груза: undefined => 0.0
    std::string    department_; //! Наименование структурного подразделения
    std::string    route_;  //! Маршрут
    std::string    adress_4_get_vehicle_;   //! Адрес подачи ТС
    std::string    category_vehicle_str_;   //! Категория ТС(текст)
    TransportRequestUnit(const time_t &      _time_4_get_vehicle,
                         const unsigned int  _passengers_numb = 0,
                         const float         _cargo_volume_ = 0,
                         const std::string & _department = "",
                         const std::string & _route = "",
                         const std::string & _adress_4_get_vehicle = "",
                         const std::string& _category_vehicle_str = ""
                        ) {
        
    }
};

/*! Заявка на автотранспорт (выгрузка АСАТ)
 *
 */
class TransportRequestUnitFull : public TransportRequestUnit {
    std::string    request_numb_;   //! Номер заявки
    std::string    request_id_intro_;   //! Внутренний ИД заявки исполнителя
    std::string    status_description_; //! Описание статуса
    time_t         time_return_vehicle_;    //! Время возвращения ТС
    std::string    priority_str_;  //! Приоритет (string)
    unsigned short priority_code_;  //! Приоритет (uint)
    std::string    request_type_str_;   //! Тип заявки
    std::string    employee_full_name_; //! ФИО сотрудника
    std::string    purpose_trip;    //! Цель поездки
             int   category_vehicle_code_;   //! Категория ТС(int)
    std::string    gosnomer_vehicle_;   //! госномер ТС
    std::string    setevoynomer_vehicle_;    //! сетевой номер ТС
    bool           is_intercity_;   //! междугороднаяя перевозка (признак)
             int   reject_reason_;  //! причина отказа
    std::string    reject_reason_str_;  //! причина отказа (текст) 
    std::string    answer_;  //! все поля с меткой Ответ: (разделены символом ';')
             int   affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
    std::string    signature_pixmap_;   //! пиктограмма подписи
    std::string    signature_fullname_; //! ФИО подписавшего
    time_t         signature_time_; //! дата и время подписи
    std::string    waybill_number_; //! Номер путевого листа
    time_t         OTZ_time_beg_;   //! ОТЗ. дата и Время начала
    time_t         OTZ_time_end_;   //! ОТЗ. дата и Время конца
    float          OTZ_timework_;   //! ОТЗ. Время работы на заказчика

    std::string    OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
    bool           is_vehicle_not_RZD_; //! ТС не РЖД (признак)
    std::string    MTA_numb_executor_;  //! Номер МТА от Исполнителя
             int   area_department_;    //! Участок структурного подразделения
    std::string    violations_str_; //! Наименование нарушения при выполнении
             int   BE_; //! БЕ
    time_t         request_time_;   //! Дата заявки
             int   request_ID_; //! ID заявки на перевозку
             int   request_status_; //! Статус заявки на перевозку
    time_t         request_status_time_;   //! Дата и время заявки
    time_t         work_time_;   //! Время работы на заказчика
    std::string    request_type_;   //! Тип заявки на перевозку
    std::string    voucher_status_; //! Статус проверки талона
    std::string    voucher_check_errors_;//! Ошибки при сверке талона
             int   region_code_;    //! Регион
    std::string    region_str_; //! Название региона
    std::string    motor_depot_str_;    //! Наименование автобазы/автоколонны
    bool           is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков

    int read_csv(std::string filename) ;
};